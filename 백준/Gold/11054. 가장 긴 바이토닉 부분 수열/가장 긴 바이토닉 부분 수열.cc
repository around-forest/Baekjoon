#include <iostream>
using namespace std;

int n, maxLength = 0;
int series[1001], leftLength[1001], rightLength[1001], bitonic[1001];
bool check = false;

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> series[i];
        leftLength[i] = 1;
        
        for(int j = i-1; j >= 1; j--) {
            if(series[j] < series[i] && (leftLength[j] + 1) > leftLength[i]) {
                leftLength[i] = leftLength[j] + 1;
            }
        }
    }
    
    for(int i = n; i >= 1; i--) {
        rightLength[i] = 1;
        
        for(int j = i+1; j <= n; j++) {
            if(series[j] < series[i] && (rightLength[j] + 1) > rightLength[i]) {
                rightLength[i] = rightLength[j] + 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) bitonic[i] = leftLength[i] + rightLength[i] - 1;
    
    for(int i = 1; i <= n; i++) {
        if(maxLength < bitonic[i]) maxLength = bitonic[i];
    }
    
    cout << maxLength;
}
