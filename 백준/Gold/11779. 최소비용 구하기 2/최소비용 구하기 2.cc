#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, start, dest;
int dist[1001];
int path[1001] = {0, };
vector<pair<int, int>> route[1001];
vector<pair<int, int>> routeBack[1001];
vector<int> result;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dist[node] < cost) continue;
        if(node == dest) return;
        
        for(int i = 0; i < route[node].size(); i++) {
            int next = cost + route[node][i].second;
            
            if(next < dist[route[node][i].first]) {
                dist[route[node][i].first] = next;
                pq.push({next, route[node][i].first});
                path[route[node][i].first] = node;
            }
        }
    }
    
}

void solution() {
    int node = dest;
    
    while(node != start) {
        result.push_back(node);
        node = path[node];
    }
    result.push_back(start);
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        route[u].push_back({v, w});
        routeBack[v].push_back({u, w});
    }
    
    cin >> start >> dest;
    
    fill(dist, dist + 1001, 1e9);
    dijkstra();
    solution();
    
    cout << dist[dest] << '\n';
    cout << result.size() << '\n';
    for(int i = result.size() - 1; i >= 0; i--) cout << result[i] << ' ';
}