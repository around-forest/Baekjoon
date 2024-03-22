/*
F(2n) = F(n)(F(n) + 2F(n-1))
F(2n+1) = F(n-1)^2 + F(n+1)^2
*/
#include <iostream>
#include <map>
#define P 1000000007LL
using namespace std;

map<long long, long long> fibonacci;

long long fibo(long long n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(fibonacci.count(n) > 0) return fibonacci[n];
    
    if(n % 2 == 0) {
        long long tmp1 = fibo(n / 2 - 1);
        long long tmp2 = fibo(n / 2);
        fibonacci[n] = ((2 * tmp1) + tmp2) * tmp2 % P;
        return fibonacci[n];
    }
    long long tmp1 = fibo((n + 1) / 2);
    long long tmp2 = fibo((n - 1) / 2);
    fibonacci[n] = (tmp1 * tmp1 + tmp2 * tmp2) % P;
    return fibonacci[n];
    
}

int main() {
    long long n;
    
    cin >> n;
    cout << fibo(n);
}