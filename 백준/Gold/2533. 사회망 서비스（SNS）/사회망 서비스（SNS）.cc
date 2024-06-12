#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int visited[1000002];
int dp[1000002][2];
vector<int> graph[1000002];
vector<int> result;

void input() {
    for(int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 1; // node가 얼리어답터일 경우
    dp[node][1] = 0; // node가 얼이어답터가 아닐 경우
    
    for(int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        
        if(visited[next]) continue;
        dfs(next);
        dp[node][0] += min(dp[next][0], dp[next][1]);
        dp[node][1] += dp[next][0];
    }
}

int main() {
    cin >> N;
    
    input();
    dfs(1);
    
    cout << min(dp[1][0], dp[1][1]);
}