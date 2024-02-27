#include <iostream>
#include <algorithm>
using namespace std;

int tmp[100001], dp[100001];
int n, result;

void p(int index) {
    dp[index] = max(dp[index], dp[index-1] + tmp[index]);
    
    if(dp[index] > result) {
        result = dp[index];
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp[i];
        dp[i] = tmp[i];
    }
    
    result = tmp[0];
    
    for(int i = 1; i < n; i++) {
        p(i);
    }
    
    cout << result;
}