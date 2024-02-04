#include <iostream>
using namespace std;

bool eratos[1000000];

int main() {
    int t, n, count;
    
    for(int i = 2; i < 1000000; i++) {
        eratos[i] = true;
    }
    
    for(int i = 2; i <= 1000; i++) {
        if(eratos[i]) {
            for(int j = i*i; j <= 1000000; j+=i) {
                eratos[j] = false;
            }
        }
    }
    
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n;
        count = 0;
        
        for(int j = 2; j <= n/2; j++) {
            if(eratos[j] && eratos[n-j]) count++;
        }
        
        cout << count << '\n';
    }
}