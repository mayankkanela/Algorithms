// Task. The goal of this code problem is to implement an algorithm for the fractional knapsack problem.

// Input Format. The first line of the input contains the number 𝑛 of items and the capacity 𝑊 of a knapsack.
// The next 𝑛 lines define the values and weights of the items. The 𝑖-th line contains integers 𝑣𝑖 and 𝑤𝑖—the
// value and the weight of 𝑖-th item, respectively.

// Constraints. 1 ≤ 𝑛 ≤ 103, 0 ≤ 𝑊 ≤ 2 · 106; 0 ≤ 𝑣𝑖 ≤ 2 · 106, 0 < 𝑤𝑖 ≤ 2 · 106 for all 1 ≤ 𝑖 ≤ 𝑛. All the
// numbers are integers.

// Output Format. Output the maximal value of fractions of items that fit into the knapsack. The absolute
// value of the difference between the answer of your program and the optimal value should be at most
// 10−3. To ensure this, output your answer with at least four digits after the decimal point (otherwise
// your answer, while being computed correctly, can turn out to be wrong because of rounding issues).

// Sample 1.
// Input:
// 3 50
// 60 20
// 100 50
// 120 30
// Output:
// 180.0000
// To achieve the value 180, we take the first item and the third item into the bag.
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

double get_optimal_value(double capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;         
  // write your code here
    unsigned int k = 0;
    while(k < weights.size()){
      if(capacity == 0)
        return value; 
      double tempValue = values[0];
      double tempWeight = weights[0]; 
      int c  = 0;
      for(int i = 1; i < values.size(); i++){
        if(tempWeight == 0 )
          {
            tempWeight = -1000;
            tempValue = 1;
            
          }        
        if(weights[i] == 0)
        {
          weights[i] == -1000;
          values[i] == 1;
        }  
        if(weights[i] > 0)  {
          if(tempValue / tempWeight < values[i] / weights[i]){
          tempValue = values[i];    
          tempWeight = weights[i];
          c = i;
          }
        }
    
      }
      
      values[c] = 0;
      weights[c] = 0;

      if(tempWeight > 0)
      {
      if(capacity > tempWeight){
        value += tempValue;
        capacity = capacity - tempWeight;
      }
      else
      {
        value += capacity * (tempValue / tempWeight);
        capacity = 0;
        break;
      }
      }
      k++;
    }
    
  return value;
}

int main() {
  int n;
  double capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  cout << fixed;
  std::cout.precision(3) ;
  std::cout << optimal_value << std::endl;
}
