#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int parents[200001];
int height[200001];
vector<pair<int, pair<int, int>>> graph;

int find(int k) {
    if(k == parents[k]) return k;
    return parents[k] = find(parents[k]);
}

bool unionFind(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return false;
    
    if(height[u] > height[v]) swap(u, v);
    parents[u] = v;
    if(height[u] == height[v]) height[v]++;
    
    return true;
}

void reset() {
    for(int i = 0; i < m; i++) {
        parents[i] = i;
        height[i] = 1;
    }
}

int main() {
    cin >> m >> n;
    
    while(m != 0 && n != 0) {
        int maxCost = 0;
        int saveCost = 0;
        
        graph.clear();
        reset();
        
        for(int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.push_back({w, {u, v}});
            maxCost += w;
        }
        
        sort(graph.begin(), graph.end());
        
        for(int i = 0; i < graph.size(); i++) {
            if(unionFind(graph[i].second.first, graph[i].second.second)) {
                saveCost += graph[i].first;
            }
        }
        
        cout << maxCost - saveCost << '\n';
        cin >> m >> n;
    }
}
