#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

int get_largest_id(vector<double> values){
  double largest = 0.000;
  int largest_id = 0;
  for(int i = 0; i < values.size(); i++){
    if(values[i] > largest){
      largest = values[i];
      largest_id = i;
    }
  }
  return largest_id;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int highest_value_id = 0;
  
  vector<double> unit_value(weights.size());
  for(int i = 0; i < weights.size(); i++){
    unit_value[i] = (double)values[i] / (double)weights[i];
  }
  
  while(capacity > 0){
    highest_value_id = get_largest_id(unit_value);
    
    if(weights[highest_value_id] <= capacity){
      value = value + (double)values[highest_value_id];
      
      weights.erase(weights.begin() + highest_value_id);
      values.erase(values.begin() + highest_value_id);
      unit_value.erase(unit_value.begin() + highest_value_id);
      
      capacity = capacity - weights[highest_value_id];
      
    }else{
      value = value + unit_value[highest_value_id] * (double)capacity;
      
      weights[highest_value_id] = weights[highest_value_id] - capacity;
      values[highest_value_id] = values[highest_value_id] - unit_value[highest_value_id] * (double)capacity;
      
      capacity = 0;
      
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed;
  std::cout << std::setprecision(10) << optimal_value << std::endl;
  return 0;
}
