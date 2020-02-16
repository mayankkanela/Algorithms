#include <iostream>

int gcd_naive(int a, int b) {
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
long long int gcd_fast(int a, int b){
long long int smaller = (a < b)? a : b;
long long int larger = (a > b)? a : b;
  while (true)
  {
    if(larger % smaller == 0){  
      return smaller;
    }
    else
    {
      long long int temp = smaller;
      smaller = larger % smaller;
      larger = temp;
    }
    
  }
  
}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
