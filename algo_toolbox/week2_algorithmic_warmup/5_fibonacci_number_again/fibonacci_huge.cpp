#include <iostream>

 long int get_fibonacci_huge_naive(long int n, long int m) {
    if (n <= 1)
        return n;
    long long int back2 = 0;
    long long int back1 = 1;
    int i = 2;
    bool found = false;
    long long int next = 0;
    long long int next2 = 0;
    long long int current = 0;
    long long int temp = 0;
//  finding Pisano period for n    
   while (found == false)
    {
        
        current = (back1 + back2) %  m; // current no
        temp = back1;
        back2 = temp;
        next = back1 + current;
        back1 = current;
        next2 = next + current;
        if(next % m == 0 && next2 %m == 1){
            found = true;
        }
        i++;
    }
  
    back1 = 0;
    back2 = 1;
 //  std:: cout<<i<<" "<<(n % i)<<"  " ;
    current = n % i;
    for(int j = 1; j < (n % i)  ; j++)
        {
            current = (back1 + back2) % m;
            back1 = back2;
            back2 = current;
            
        }
 return current % m;    
}

int main() {
    long long int n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
