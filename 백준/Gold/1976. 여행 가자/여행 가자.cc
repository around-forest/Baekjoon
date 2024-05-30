#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, check = 0;
bool visited[202];
vector<int> graph[202];

void dfs(int node) {
    visited[node] = true;
    
    for(int i : graph[node]) {
        if(!visited[i]) dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for(int i = 1; i <= N; i ++) {
        for(int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if(tmp) graph[i].push_back(j);
        }
    }
    
    for(int i = 1; i <= M; i++) {
        int tmp;
        cin >> tmp;
        
        if(!visited[tmp]) {
            check++;
            dfs(tmp);
        }
    }
    
    if(check == 1) cout << "YES";
    else cout << "NO";
}