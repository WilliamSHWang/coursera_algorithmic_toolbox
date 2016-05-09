#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
vector<int> bubble_fast(vector<int> input){
  int n = input.size();
  while(true){
    int newn = 0;
    for(int i=1; i<=n-1; i++){
      if(input[i-1] > input[i]){
        std::swap(input[i-1], input[i]);
        newn = i;
      }
    }
    n = newn;
    if(n==0) break;
  }
  return input;
}

long long min_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  vector<int> as = bubble_fast(a);
  vector<int> bs = bubble_fast(b);
  
  int length = as.size();
  
  for (int i = 0; i < length; i++) {
    result += as[i] * bs[(length-1)-i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << min_dot_product(a, b) << std::endl;
}
