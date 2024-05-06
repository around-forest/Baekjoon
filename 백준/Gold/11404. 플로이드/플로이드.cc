#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int n, m;
int dp[102][102];

void floydWarshall() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = min(dp[u][v], w);
    }
    
    floydWarshall();
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || dp[i][j] == INF) cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}