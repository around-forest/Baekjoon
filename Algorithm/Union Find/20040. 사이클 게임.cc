#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt = 1, result = 0;
int parents[500002];
int height[500002];

int find(int k) {
    if(k == parents[k]) return k;
    return parents[k] = find(parents[k]);
}

void unionFind(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) {
        result = cnt;
        return;
    }
    
    if(height[u] > height[v]) swap(u, v);
    parents[u] = v;
    if(height[u] == height[v]) height[v]++;
}

void reset() {
    for(int i = 0; i < n; i++) {
        parents[i] = i;
        height[i] = 1;
    }
}

int main() {
    cin >> n >> m;
    
    reset();
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if(result == 0) unionFind(u, v);
        
        cnt++;
    }
    
    cout << result;
}
