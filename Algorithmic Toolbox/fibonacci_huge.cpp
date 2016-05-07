#include <iostream>
#include <vector>
#include <stdlib.h>

long long get_fibonaccihuge(long long n, long long m) {
  //write your code here
  
  if (n <= 1){
    return n;
  }else{
    long long period = 0;
    std::vector<int> f;
    f.push_back(0);
    f.push_back(1);
    for(long long i=2; i<=n; i++){
      period++;
      f.push_back((f[i-1] + f[i-2]) % m);
      if(f.back() == 1 && f[f.size()-2] == 0)
        break;
    }
    long long index = n % period;
    return f[index];
  }
  return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}
