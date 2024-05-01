#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int N, E, V1, V2, pathV1, pathV2, result;
bool checkV1, checkV2;
int dist[802];
vector<pair<int, int>> graph[802];
priority_queue<pair<int, int>> pq;

void dijkstra(int start) {
    fill(dist, dist+802, INF);
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dist[node] < cost) continue;
        
        for(int i = 0; i < graph[node].size(); i++) {
            int next = cost + graph[node][i].second;
            
            if(next < dist[graph[node][i].first]) {
                dist[graph[node][i].first] = next;
                pq.push({-next, graph[node][i].first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> E;
    
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    cin >> V1 >> V2;
    
    checkV1 = true;
    checkV2 = true;
    
    dijkstra(1);
    
    pathV1 = dist[V1]; // shortest path from 1 to V1
    pathV2 = dist[V2]; // shortest path from 1 to V2
    
    if(pathV1 == INF) checkV1 = false; // no path from 1 to V1
    if(pathV2 == INF) checkV2 = false; // no path from 1 to V2
    
    dijkstra(V1); // shortest path from V1
    
    if(checkV1) pathV1 += dist[V2]; // shortest path from 1 to V1 to V2
    if(checkV2) {
        pathV2 += dist[V2]; // shortest path from 1 to V2 to V1
        pathV2 += dist[N]; // shortest path from 1 to V2 to V1 to N
    }
    
    dijkstra(V2); // shortest path from V2
    
    if(checkV1) pathV1 += dist[N]; // shortest path from 1 to V1 to V2 to N
    
    result = min(pathV1, pathV2);
    
    if(!checkV1 || !checkV2 || result >= INF) result = -1;
    
    cout << result;
}
