#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, cnt = 0;
int result[100001];
bool check[100001];
vector<int> graph[100001];
queue<int> tmp;

void bfs(int r) {
    check[r] = true;
    
    tmp.push(r);
    while(!tmp.empty()) {
        int u = tmp.front();
        tmp.pop();
        
        cnt++;
        result[u] = cnt;
        
        for(int i = 0; i < graph[u].size(); i++) {
            if(!check[graph[u][i]]) {
                check[graph[u][i]] = true;
                tmp.push(graph[u][i]);
            }
        }
    }
}

int main() {
    cin >> N >> M >> R;
    
    for(int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    
    bfs(R);
    
    for(int i = 1; i <= N; i++) {
        cout << result[i] << '\n';
    }
}