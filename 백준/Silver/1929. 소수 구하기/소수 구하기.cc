#include <iostream>
using namespace std;

bool isPrime(int m) {
    if(m <= 1) return false;
    if(m == 2 || m == 3) return true;
    if(m % 2 == 0 || m % 3 == 0) return false;
    
    for(int i = 5; i*i <= m; i++) {
        if(m % i == 0 || m % (i+2) == 0) return false;
    }
    return true;
}

int main() {
    int m, n, prime;
    
    cin >> m >> n;
    
    while(m <= n) {
        if(isPrime(m)) {
            cout << m << '\n';
        }
        m++;
    }
}