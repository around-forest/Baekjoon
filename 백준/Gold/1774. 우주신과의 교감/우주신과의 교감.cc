#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, M;
double result = 0;
int parents[1001];
int height[1001];
vector<pair<int, int>> god;
vector<pair<double, pair<int, int>>> graph;

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
    for(int i = 0; i <= N; i++) {
        parents[i] = i;
        height[i] = 1;
    }
}

int main() {
    cin >> N >> M;
    
    reset();
    
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        god.push_back({a, b});
    }
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        unionFind(a-1, b-1);
    }
    
    for(int i = 0; i < god.size(); i++) {
        for(int j = i + 1; j < god.size(); j++) {
            double dist = sqrt(pow((god[i].first - god[j].first), 2) + pow((god[i].second - god[j].second), 2));
            graph.push_back({dist, {i, j}});
        }
    }
    
    sort(graph.begin(), graph.end());
    
    for(int i = 0; i < graph.size(); i++) {
        if(unionFind(graph[i].second.first, graph[i].second.second)) {
            result += graph[i].first;
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << result;
}