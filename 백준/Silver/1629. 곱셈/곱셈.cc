#include <iostream>
using namespace std;

long long A, B, C, tmp;

long long merge(long long b) {
    if(b == 0) return 1;
    if(b == 1) return A % C;
    
    tmp = merge(b/2) % C;
    
    if(b % 2 == 0) {
        return tmp * tmp % C;
    }
    return tmp * tmp % C * A % C;
}

int main() {
    cin >> A >> B >> C;
    
    cout << merge(B);
}