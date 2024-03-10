#include <iostream>
#include <algorithm>
using namespace std;

int n, k, maxValue = 0;
int W[101], V[101], DP[101][100001] = {0,};

int main() {
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(W[i] > j) DP[i][j] = DP[i-1][j];
            else DP[i][j] = max(DP[i-1][j], DP[i-1][j-W[i]] + V[i]);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(DP[i][k] > maxValue) maxValue = DP[i][k];
    }
    
    cout << maxValue;
}
