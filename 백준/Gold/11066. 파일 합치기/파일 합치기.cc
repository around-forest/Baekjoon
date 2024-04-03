#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int T, K;
int dp[501][501];
int sum[501] = {0,};

int main() {
    cin >> T;
    
    while(T--) {
        cin >> K;
        
        for(int i = 1; i <= K; i++) {
            int tmp;
            cin >> tmp;
            sum[i] = sum[i-1] + tmp;
        }
        
        for(int i = 1; i < K; i++) {
            for(int x = 1; x <= K - i; x++) {
                int y = x + i;
                dp[x][y] = INT_MAX;
                
                for(int mid = x; mid < y; mid++) {
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x-1]);
                    // x~mid 까지의 최소비용 + mid+1~y 까지의 최소비용 + x~y 까지의 합
                }
            }
        }
        cout << dp[1][K] << '\n';
    }
}