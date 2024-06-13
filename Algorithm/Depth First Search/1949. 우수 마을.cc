#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
int dp[10002][2];
bool visited[10002];
vector<int> graph[10002];

void input() {
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> dp[i][1];
    }
    
    for(int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int node) {
    visited[node] = true;
    
    for(int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        
        if(visited[next]) continue;
        dfs(next);
        
        dp[node][0] += max(dp[next][0], dp[next][1]);
        dp[node][1] += dp[next][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    dfs(1);
    
    cout << max(dp[1][0], dp[1][1]);
}
