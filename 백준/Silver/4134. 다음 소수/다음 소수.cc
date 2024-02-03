#include <iostream>
using namespace std;

bool isPrime(long long test) {
    if(test <= 1) return false;
    if(test == 2 || test == 3) return true;
    if(test % 2 == 0 || test % 3 == 0) return false;
    
    for(long long i = 5; i*i <= test; i++) {
        if(test % i == 0 || test % (i+2) == 0) return false;
    }
    return true;
}

int main() {
    long long n, test;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> test;
        
        while(!isPrime(test)) {
            test++;
        }
        
        cout << test << '\n';
    }
        
}