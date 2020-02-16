// The goal in this problem is to find the minimum number of coins needed to change the input value
// (an integer) into coins with denominations 1, 5, and 10.

//Input Format. The input consists of a single integer 𝑚.
// Constraints. 1 ≤ 𝑚 ≤ 103.
// Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.
#include <iostream>
using namespace std;

int get_change(int m) {
  //write your code here
  int n = 0;
  n = m / 10;
  m = m % 10;
 
  if(m > 5 ){
    n += m / 5;
    m = m % 5;
  }
  n += m;
  
  return n;   
}// Time: O(1)

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
