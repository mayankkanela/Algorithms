#include <iostream>
#include <cassert>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
long long int fibonacci_sum_fast (long long n){
    if(n <= 1)
    return n;
    if(n % 60 == 0)
    return 0;
    int i = 1;
    long long int a = 0, b = 1;
    long long int c = 1;
//    std::cout<< n / 60 <<"\n";
    while (i < 60)
    {
        long long int temp = a ;//01
        a = b;//11
        b = temp % 10 + b % 10;//12
        c = (c + b) % 10 ;//24
        i++;
    }
//    std::cout << c <<"\n ";
    int j = 0;
    a = 0;
    b = 1;
    int d = 1;
    while(j < (n % 60) - 1){//0
        long long int temp = a; //0
        a = b;//1
        b = b % 10 + temp % 10;//1
        d = (d + b) % 10;//1
        j++;
    }
//   std::cout <<    n % 60  << ", "<<d % 10 <<"\n" ; 
    return ((n / 60) * c + d) % 10;
    /* NOTE: no fib 60 sum last dig is coming out to be 0 so even less loop req just cal n%60 fibs */
}
void test_solution() {
    
    // assert(fibonacci_sum_fast(3) == 4);
    // assert(fibonacci_sum_fast(100) == 5);
    for (int n = 0; n < 100; ++n){  
        std::cout << fibonacci_sum_naive(n) << " " <<  fibonacci_sum_fast(n) << " " << n << std::endl; 
        assert(fibonacci_sum_fast(n) == fibonacci_sum_naive(n));
    }
}


int main() {
    long long n = 0;
    std::cin >> n;
//    test_solution();
    std::cout << fibonacci_sum_fast(n);
}
