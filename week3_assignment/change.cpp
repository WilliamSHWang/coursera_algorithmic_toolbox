#include <iostream>

int get_change(int n) {
  //write your code here
  if(n >= 10){
    return get_change(n % 10) + (n / 10);
  }else if(n >= 5){
    return get_change(n % 5) + (n / 5);
  }else{
    return n;
  }
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
