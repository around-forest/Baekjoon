#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int dp[10002][2];
bool visited[10002];
vector<int> graph[10002];
vector<int> result;

void input() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> dp[i][1];
        dp[i][0] = 0;
    }
    
    for(int i = 1; i < n; i++) {
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
        
        if(!visited[next]) {
            dfs(next);
            dp[node][0] += max(dp[next][0], dp[next][1]);
            dp[node][1] += dp[next][0];
        }
    }
    // dp[x][0] -> 내가 포함되지 않았을 때의 최대 값
    // dp[x][1] -> 내가 포함되었을 때의 최대 값
    // 현재와 다음 모두 포함 x / 현재 포함 x 다음 포함 o / 현재 포함 o 다음 포함 x의
    // 경우만 있으므로 dp[x][1] += dp [x][1] 이 없는 것
}

void trace(int node, int prev) {
    if(dp[node][0] < dp[node][1] && !visited[prev]) {
        result.push_back(node);
        visited[node] = true;
    }
    
    for(int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if(prev != next) {
            trace(next, node);
        } 
    }
}

int main() {
    input();
    
    dfs(1);
    memset(visited, false, sizeof(visited));
    
    trace(1, 0);
    
    sort(result.begin(), result.end());
    
    cout << max(dp[1][0], dp[1][1]) << '\n';
    for(int i : result) cout << i << ' ';
}
