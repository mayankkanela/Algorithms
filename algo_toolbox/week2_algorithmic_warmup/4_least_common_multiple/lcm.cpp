#include <iostream>

long long lcm_fast(int a, int b) {
  for (long l = (a > b) ? a : b; l <= (long long) a * b; l += (a > b) ? a : b)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
