#include <iostream>
using namespace std;

int main() {
    int n, k, nf = 1, kf = 1, nkf = 1;
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) nf = nf * i;
    for(int i = 1; i <= k; i++) kf = kf * i;
    for(int i = 1; i <= (n-k); i++) nkf = nkf * i;
    
    cout << nf / (kf * nkf);
}