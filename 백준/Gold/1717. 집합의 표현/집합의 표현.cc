#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int parent[1000002];
int height[1000002];

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unionFind(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return;
    
    if(height[u] > height[v]) swap(u, v);
    parent[u] = v;
    if(height[u] == height[v]) height[v]++;
}

void reset() {
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        height[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    reset();
    
    for(int i = 0; i < m; i++) {
        int c, u, v;
        cin >> c >> u >> v;
        
        if(c == 0) {
            unionFind(u, v);
        } else if(c == 1) {
            u = find(u);
            v = find(v);
            if(u == v) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}