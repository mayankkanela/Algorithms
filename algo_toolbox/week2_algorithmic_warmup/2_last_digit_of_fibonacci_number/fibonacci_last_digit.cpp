#include <iostream>

long long int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long int a[n];
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i<n; i++)
    {
        a[i] = a[i-1]%10 + a[i-2]%10;
    }
    return a[n-1]%10;
}

int main() {
    int n;
    std::cin >> n;
    long long int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
