#include <iostream>
using namespace std;

bool isPrime(int m) {
    if(m == 2 || m == 3) return true;
    if(m % 2 == 0 || m % 3 == 0) return false;
    
    for(int i = 5; i*i <= m; i++) {
        if(m % i == 0 || m % (i+2) == 0) return false;
    }
    return true;
}

int main() {
    int n, count = 0;
    
    cin >> n;
    
    while(n != 0) {
        for(int i = n+1; i <= n*2; i++) {
            if(isPrime(i)) count++;
        }
        cout << count << '\n';
        cin >> n;
        count = 0;
    }
    
}