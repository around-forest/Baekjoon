#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, cnt = -1;
bool check[101];
vector<int> graph[101];

void dfs(int r) {
    if(check[r]) return;
    
    check[r] = true;
    cnt++;
    
    for(int i = 0; i < graph[r].size(); i++) {
        dfs(graph[r][i]);
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(1);
    
    cout << cnt;
}