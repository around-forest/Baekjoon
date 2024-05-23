#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, maxNode, maxDist = 0;
bool visited[10001];
vector<pair<int, int>> graph[10001];

void dfs(int node, int dist) {
    if(visited[node]) return;
    visited[node] = true;
    
    if(dist > maxDist) {
        maxDist = dist;
        maxNode = node;
    }
    
    for(int i = 0; i < graph[node].size(); i++) {
        dfs(graph[node][i].first, dist + graph[node][i].second);
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    dfs(1, 0);
    
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    
    dfs(maxNode, 0);
    
    cout << maxDist;
}
