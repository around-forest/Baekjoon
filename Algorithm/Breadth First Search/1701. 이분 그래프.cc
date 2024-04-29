#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int K, V, E;
int check[20002] = {0, };
vector<int> graph[20001];
queue<int> q;

void bfs(int r) {
    check[r] = 1;
    q.push(r);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i = 0; i < graph[node].size(); i++) {
            if(!check[graph[node][i]]) {
                if(check[node] == 1) {
                    check[graph[node][i]] = 2;
                    q.push(graph[node][i]);
                } else if(check[node] == 2) {
                    check[graph[node][i]] = 1;
                    q.push(graph[node][i]);
                }
            }
        }
    }
}

void isBipartite() {
    for(int i = 1; i <= V; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            if(check[i] == check[graph[i][j]]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K;
    
    while(K--) {
        cin >> V >> E;
        
        for(int i = 0; i < E; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        
        for(int i = 1; i <= V; i++) {
            if(!check[i]) {
                bfs(i);
            }
        }
        
        isBipartite();
        
        for(int i = 0; i <= V; i++) {
            graph[i].clear();
            check[i] = 0;
        }
    }
}
