#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int V, E, K, sum = 0;
int dist[20002]; // 최단거리 저장 배열
vector<pair<int, int>> graph[20002]; // 방향 그래프 저장 벡터
priority_queue<pair<int, int>> pq; // 이동 노드의 순서 저장 우선순위 큐

void dijkstra(int start) {
    pq.push({0, start}); // 시작 노드 방문
    dist[start] = 0; // 시작 노드의 가중치 0
    
    while(!pq.empty()) {
        int cost = -pq.top().first; // 이동 노드까지의 최소 거리 비용 (음수로 저장된 거리 비용을 양수로 변환)
        int node = pq.top().second; // 이동 노드의 순서에 따른 노드
        pq.pop();
        
        if(dist[node] < cost) continue; // 현재 노드의 거리 비용이 이미 최소일 경우
        
        for(int i = 0; i < graph[node].size(); i++) { // 현재 노드와 연결된 간선 수 만큼 반복
            int next = cost + graph[node][i].second; // 현재 노드와 연결된 다음 노드의 거리 비용 (현재 노드 최소 비용 + 다음 노드까지 가중치)
            
            if(next < dist[graph[node][i].first]) { // 다음 노드의 새로운 거리 비용이 기존 거리 비용보다 작을 경우
                dist[graph[node][i].first] = next; // 거리 비용 갱신
                pq.push({-next, graph[node][i].first}); // 이동 순서 큐에 노드 및 거리 비용 음수로 저장 (우선순위 큐는 내림차순이므로 큰 거리 비용이 맨 뒤로 가게 함) 
            }
        }
    }
}

int main() {
    cin >> V >> E >> K;
    
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u].push_back({v, w});
    }
    
    fill(dist, dist + 20002, INT_MAX);
    
    dijkstra(K);
    
    for(int i = 1; i <= V; i++) {
        if(dist[i] == INT_MAX) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}