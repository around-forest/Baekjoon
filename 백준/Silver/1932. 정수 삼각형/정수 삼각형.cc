#include <iostream>
#include <algorithm>
using namespace std;

int tmp[501];
int dp[501] = {0,};
int result[501] = {0,};

int main() {
    int n, sum = 0;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cin >> tmp[j];
            
            result[j] = max(dp[j-1], dp[j]) + tmp[j];
        }
        
        for(int j = 0; j < i; j++) {
            dp[j] = result[j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(result[i] > sum) sum = result[i];
    }
    
    cout << sum;
}