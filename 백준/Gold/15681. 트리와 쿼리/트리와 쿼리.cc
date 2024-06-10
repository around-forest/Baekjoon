#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int N, R, Q;
int dp[100005];
bool visited[100005];
vector<int> graph[100005];

int dfs(int root) {
    int cnt = dp[root];
    if(cnt != 0) return cnt;
    
    cnt = 1;
    
    for(int i = 0; i < graph[root].size(); i++) {
        if(!visited[graph[root][i]]) {
            visited[graph[root][i]] = true;
            cnt += dfs(graph[root][i]);
        }
    }
    
    return dp[root] = cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> N >> R >> Q;
    
    for(int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    visited[R] = true;
    dfs(R);
    
    for(int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        
        cout << dfs(q) << '\n';
    }
}