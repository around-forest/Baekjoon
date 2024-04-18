#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
bool check1[1001];
bool check2[1001];
vector<int> graph[1001];
queue<int> q;

void dfs(int v) {
    if(check1[v]) return;
    
    check1[v] = true;
    cout << v << ' ';
    
    for(int i = 0; i < graph[v].size(); i++) {
        dfs(graph[v][i]);
    }
}

void bfs(int v) {
    check2[v] = true;
    q.push(v);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for(int i = 0; i < graph[u].size(); i++) {
            if(!check2[graph[u][i]]) {
                check2[graph[u][i]] = true;
                q.push(graph[u][i]);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;
    
    for(int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(V);
    cout << '\n';
    bfs(V);
}
