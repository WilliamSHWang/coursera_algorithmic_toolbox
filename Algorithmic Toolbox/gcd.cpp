#include <iostream>
#include <stdlib.h>

int gcd(int a, int b) {
  //write your code here
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_fast(long long a, long long b){
  if(b > a) std::swap(a, b);
  if(b == 0) return a;
  return gcd_fast(b, a % b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  
  // int fast = 0;
  // int slow = 0;
  // while(1){
  //     a = rand() % 100000;
  //     b = rand() % 100000;
  //     fast = gcd_fast(a, b);
  //     slow = gcd(a, b);
  //     if(fast == slow){
  //       std::cout << a << "" << b << std::endl;
  //       std::cout << slow << " " << fast << std::endl;
  //       std::cout << "OK!" << std::endl;
  //     }else{
  //       std::cout << a << "" << b << std::endl;
  //       std::cout << slow << " " << fast << std::endl;
  //       std::cout << "NOT OK!" << std::endl;
  //       break;
  //     } 
  //   }
  return 0;
}
