#include <iostream>
using namespace std;

int main() {
    int n, k, count = 0;
    int coin[11];
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) cin >> coin[i];
    
    for(int i = n-1; i >= 0; i--) {
        if(coin[i] <= k) {
            count += (k / coin[i]) ;
            k %= coin[i];
        }
        
        if(k == 0) break;
    }
    
    cout << count;
}