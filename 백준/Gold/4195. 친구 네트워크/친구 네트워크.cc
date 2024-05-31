#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int T, F;
unordered_map<string, string> parents;
unordered_map<string, int> height;
unordered_map<string, int> num;

string find(string k) {
    if(k == parents[k]) return k;
    return parents[k] = find(parents[k]);
}

void unionFind(string u, string v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return;
    
    if(height[u] > height[v]) swap(u, v);
    parents[u] = v;
    if(height[u] == height[v]) height[v]++;
    
    num[v] += num[u];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while(T--) {
        cin >> F;
        
        parents.clear();
        height.clear();
        num.clear();
        
        while(F--) {
            string u, v;
            cin >> u >> v;
            
            if(parents.count(u) == 0) {
                parents.insert({u, u});
                height.insert({u, 1});
                num.insert({u, 1});
            }
            
            if(parents.count(v) == 0) {
                parents.insert({v, v});
                height.insert({v, 1});
                num.insert({v, 1});
            }
            
            unionFind(u, v);
            
            cout << num[find(u)] << '\n';
        }
    }
}