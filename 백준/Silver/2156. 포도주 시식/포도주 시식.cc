#include <iostream>
#include <algorithm>
using namespace std;

int wine[10001] = {0,};
int dp[10001] = {0,};

int main() {
    int n;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-2] + wine[i], max(dp[i-3] + wine[i-1] + wine[i], dp[i-1]));
    }
    
    cout << dp[n];
}