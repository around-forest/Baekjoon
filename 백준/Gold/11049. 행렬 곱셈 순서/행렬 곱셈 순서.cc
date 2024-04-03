#include <iostream>
#include <climits>
using namespace std;

int N;
int matrix[501][2];
int dp[501][501];

int main() {
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }
    
    for(int i = 1; i < N; i++) {
        for(int x = 1; x <= N - i; x++) {
            int y = x + i;
            dp[x][y] = INT_MAX;
            
            for(int mid = x; mid < y; mid++) {
                dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + (matrix[x][0] * matrix[mid][1] * matrix[y][1]));
                // x~mid, mid+1~y 의 최소값 + x행렬 * mid행렬 * y행렬
            }
        }
    }
    
    cout << dp[1][N];
}