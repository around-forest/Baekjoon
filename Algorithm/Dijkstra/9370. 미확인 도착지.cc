#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX 2002

using namespace std;

int T, n, m, t;
int s, g, h;
int distS[MAX], distG[MAX], distH[MAX];
vector<int> candidates;
vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start, int array[MAX]) {
    fill(array, array+MAX, INF);
    
    pq.push({0, start});
    array[start] = 0;
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(cost > array[node]) continue;
        
        for(int i = 0; i < graph[node].size(); i++) {
            int next = cost + graph[node][i].second;
            
            if(next < array[graph[node][i].first]) {
                array[graph[node][i].first] = next;
                pq.push({next, graph[node][i].first});
            }
        }
    }
}

void solution() {
    // path from s
    dijkstra(s, distS);
    // path from g
    dijkstra(g, distG);
    // path from h
    dijkstra(h, distH);
    
    int distGH = distG[h];
    
    sort(candidates.begin(), candidates.end());
    
    for(int i = 0; i < candidates.size(); i++) {
        int dest = candidates[i];
        
        if(distS[dest] == distS[g] + distGH + distH[dest]) cout << dest << ' ';
        else if(distS[dest] == distS[h] + distGH + distG[dest]) cout << dest << ' ';
    }
    
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> T;
    
    while(T--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        
        for(int i = 0; i < t; i++) {
            int tmp;
            cin >> tmp;
            candidates.push_back(tmp);
        }
        
        solution();
        
        for(int i = 0; i < MAX; i++) {
            graph[i].clear();
            distH[i] = INF;
            distG[i] = INF;
            distS[i] = INF;
        }
        candidates.clear();
    }
}
