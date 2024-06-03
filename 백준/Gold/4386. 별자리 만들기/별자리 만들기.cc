#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
double result = 0;
int parents[101];
int height[101];
vector<pair<double, double>> stars;
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
    for(int i = 0; i < n; i++) {
        parents[i] = i;
        height[i] = 1;
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }
    
    reset();
    
    for(int i = 0; i < stars.size(); i++) {
        for(int j = i + 1; j < stars.size(); j++) {
            double dist = sqrt(pow((stars[i].first - stars[j].first), 2) + pow((stars[i].second - stars[j].second), 2));
            
            graph.push_back({dist, {i, j}});
        }
    }
    
    sort(graph.begin(), graph.end());
    
    for(int i = 0; i < graph.size(); i++) {
        if(unionFind(graph[i].second.first, graph[i].second.second)) {
            result += graph[i].first;
        }
    }
    
    cout.precision(3);
    cout << result;
}