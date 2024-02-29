#include <iostream>
#include <algorithm>
using namespace std;

int stairs[301] = {0,};
int dp[301] = {0,};

int main() {
    int n;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }
    
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
    }
    
    cout << dp[n];
}