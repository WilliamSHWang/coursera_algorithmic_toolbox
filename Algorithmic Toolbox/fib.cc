#include <iostream>
#include <vector>
#include <stdlib.h>

int calc_fib(int n) {
    if (n <= 1){
        return n;
    }else{
      std::vector<int> f;
      f.push_back(0);
      f.push_back(1);
      for(int i=2; i<=n; i++){
        f.push_back(f[i-1] + f[i-2]);
      }
      return f.back();
    }
    //return calc_fib(n - 1) + calc_fib(n - 2);
}

int calc_fib_rec(int n) {
  if (n <= 1)
  	return n;

  return calc_fib_rec(n - 1) + calc_fib_rec(n - 2);
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << calc_fib(n) << '\n';

  	 //int fast = 0;
  	 //int slow = 0;
    //while(1){
    //  n = rand() % 46;
    //  fast = calc_fib(n);
    //  slow = calc_fib_rec(n);
    //  if(fast == slow){
    //    std::cout << n << std::endl;
    //    std::cout << slow << " " << fast << std::endl;
    //    std::cout << "OK!" << std::endl;
    //  }else{
    //    std::cout << n << std::endl;
    //    std::cout << slow << " " << fast << std::endl;
    //    std::cout << "NOT OK!" << std::endl;
    //    break;
    //  } 
    //}
  
    return 0;
}
