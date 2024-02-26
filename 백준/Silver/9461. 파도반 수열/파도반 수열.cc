#include <iostream>
using namespace std;

long long tmp[101] = {0, 1, 1,};

long long p(int n) {
    if(n < 3) return tmp[n];
    else if(tmp[n] == 0) tmp[n] = p(n-2) + p(n-3);
    return tmp[n];
}

int main() {
    int t, n;
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        cout << p(n) << '\n';
    }
}