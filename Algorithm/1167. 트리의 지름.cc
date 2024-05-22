#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int v, maxDist = 0, maxNode;
bool visited[100001];
vector<pair<int, int>> graph[100001];

void dfs(int node, int dist) {
    if(visited[node]) return;
    
    if(maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }
    
    visited[node] = true;
    for(int i = 0; i < graph[node].size(); i++) {
        dfs(graph[node][i].first, dist + graph[node][i].second);
    }
}

int main() {
    cin >> v;
    
    for(int i = 0; i < v; i++) {
        int from, to, dist;
        cin >> from >> to;
        
        while(to != -1) {
            cin >> dist;
            graph[from].push_back({to, dist});
            cin >> to;
        }
    }
    
    dfs(1, 0);
    
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    
    dfs(maxNode, 0);
    
    cout << maxDist;
}
