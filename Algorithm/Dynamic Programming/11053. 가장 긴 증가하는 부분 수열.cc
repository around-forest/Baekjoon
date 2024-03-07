#include <iostream>
using namespace std;

int n, maxLength = 0;
int series[1001], length[1001];

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> series[i];
        length[i] = 1;
        
        for(int j = i-1; j >= 1; j--) {
            if(series[j] < series[i] && (length[j] + 1) > length[i]) {
                length[i] = length[j] + 1;
            }
        }
        
        if(length[i] > maxLength) maxLength = length[i];
    }
    
    cout << maxLength;
}
