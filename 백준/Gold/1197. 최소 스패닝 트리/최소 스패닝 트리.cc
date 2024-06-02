#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int V, E, result = 0;
int parents[10001];
int height[10001];
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
    for(int i = 1; i <= V; i++) {
        parents[i] = i;
        height[i] = 1;
    }
}

int main() {
    cin >> V >> E;
    
    reset();
    
    for(int i = 1; i <= E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    
    sort(graph.begin(), graph.end());
    
    for(int i = 0; i < graph.size(); i++) {
        if(unionFind(graph[i].second.first, graph[i].second.second)) {
            result += graph[i].first;
        }
    }
    
    cout << result;
}