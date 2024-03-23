#include <iostream>
#include <map>
using namespace std;

long long n, m, tmp;
map<long long, long long> A;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        A[tmp] = 1;
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        
        if(A[tmp]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
