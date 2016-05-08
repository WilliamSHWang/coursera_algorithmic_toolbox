#include <iostream>
#include <vector>
#include <stdlib.h>

int get_fibonacci_last_digit(int n) {
  //write your code here
  if (n <= 1){
      return n;
  }else{
      std::vector<int> f;
      f.push_back(0);
      f.push_back(1);
      for(int i=2; i<=n; i++){
        f.push_back((f.back() + f[f.size()-2]) % 10);
        f.erase(f.begin());
      }
      return f.back();
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
  
    return 0;
}
