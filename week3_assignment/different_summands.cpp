#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  
  summands.push_back(0);
  
  while(true){
    n = n - summands.back();
    if(n <= 2*(summands.back()+1)){
      summands.push_back(n);
      break;
    }else{
      summands.push_back(summands.back()+1);
    }
  }
  summands.erase(summands.begin());
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout << std::endl;
}
