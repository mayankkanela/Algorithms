#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int leftElement = get_majority_element(a, left, (left + right - 1) / 2 + 1);
  int rightElement = get_majority_element(a, (left + right - 1) / 2 + 1, right);

  int lc = 0;
  for (int i = left; i < right; i++)
  {
    if(a[i] == leftElement)
      lc++;
  }
  if(lc > (right  - left) / 2)
  return leftElement;

  int rc = 0;
  for (int i = left; i < right; i++)
  {
    if(a[i] == rightElement)
      lc++;
  }
  if(lc > (right  - left) / 2)
  return rightElement;
  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
