// Car Fueling

// Problem Introduction

// You are going to travel to another city that is located 𝑑 miles away from your home city. Your car can travel
// at most 𝑚 miles on a full tank and you start with a full tank. Along your way, there are gas stations at
// distances stop1, stop2, . . . , stop𝑛 from your home city. What is the minimum number of refills needed?

// Problem Description

// Input Format. The first line contains an integer 𝑑. The second line contains an integer 𝑚. The third line
// specifies an integer 𝑛. Finally, the last line contains integers stop1, stop2, . . . , stop𝑛.

// Output Format. Assuming that the distance between the cities is 𝑑 miles, a car can travel at most 𝑚 miles
// on a full tank, and there are gas stations at distances stop1, stop2, . . . , stop𝑛 along the way, output the
// minimum number of refills needed. Assume that the car starts with a full tank. If it is not possible to
// reach the destination, output −1.
// Constraints. 1 ≤ 𝑑 ≤ 105. 1 ≤ 𝑚 ≤ 400. 1 ≤ 𝑛 ≤ 300. 0 < stop1 < stop2 < · · · < stop𝑛 < 𝑑.
// Sample 1.
// Input:
// 950
// 400
// 4
// 200 375 550 750
// Output:
// 2

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int num_refil = 0;
    int current_refil = 0;
    int n = stops.size();
    
    while (current_refil < n - 1 )
    {
        int last_refil = current_refil;
        int temp_refil = 0;
        if(last_refil != -1)
        {
            temp_refil = stops[last_refil];
        }
        while (current_refil < n - 1  && stops[current_refil + 1] - temp_refil <= tank)
        {
            current_refil++;
        }
        if(current_refil == last_refil)
        {
            return -1;
        }

        if(current_refil < n)
        {
             num_refil = num_refil + 1;
        }
    }
    if(dist - (stops[current_refil] + tank ) <= 0 )
    return num_refil;
    else
    {
        return -1;
    }
   
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
