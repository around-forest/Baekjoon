#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;

int N, M;
long long dist[502];
vector<pair<int, pair<int, int>>> graph;

void bellmanFord(int start) {
    fill(dist, dist+502, INF);
    
    dist[start] = 0;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            int from = graph[j].first;
            int to = graph[j].second.first;
            int cost = graph[j].second.second;
            
            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                
                if(i == N) {
                    cout << -1;
                    return;
                }
            }
        }
    }
    
    for(int i = 2; i <= N; i++) {
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph.push_back({A, {B, C}});
    }
    
    bellmanFord(1);
}
