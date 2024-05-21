#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int dp[105][105];
int p[105][105];
vector<int> path;

void floydWarshall() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dp[i][j] > dp[i][k] + dp[k][j]) {
                    p[i][j] = k;
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}

void route(int start, int dest) {
    if(p[start][dest] != 0) {
        route(start, p[start][dest]);
        path.push_back(p[start][dest]);
        route(p[start][dest], dest);
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            p[i][j] = 0;
            
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = 1e9;
        }
    }
    
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        dp[u][v] = min(dp[u][v], w);
    }
    
    floydWarshall();
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dp[i][j] == 1e9) cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || dp[i][j] == 1e9) {
                cout << 0 << '\n';
                continue;
            }
            
            route(i, j);
            
            cout << path.size() + 2 << ' ' << i << ' ';
            for(int k = 0; k < path.size(); k++) {
                cout << path[k] << ' ';
            }
            cout << j << '\n';
            path.clear();
        }
    }
}