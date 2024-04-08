#include <iostream>
#include <algorithm>
using namespace std;

int N, M, sum = 0;
int A[101];
int C[101];
int dp[101][10001];

int main() {
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    for(int i = 1; i <= N; i++) {
        cin >> C[i];
        sum += C[i];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= sum; j++) {
            if(j - C[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-C[i]] + A[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    
    for(int i = 0; i <= sum; i++) {
        if(dp[N][i] >= M) {
            cout << i;
            break;
        }
    }
}