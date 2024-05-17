#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int parent[100002];
bool check[100002];
vector<int> path;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start) {
    pq.push({0, start});
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        check[node] = true;
        
        if(node == K) {
            int index = node;
            while(index != N) {
                path.push_back(index);
                index = parent[index];
            }
            cout << cost << '\n';
            break;
        }
        
        if(node-1 >= 0 && !check[node-1]) {
            pq.push({cost+1, node-1});
            check[node-1] = true;
            parent[node-1] = node;
        }
        if(node+1 <= 100000 && !check[node+1]) {
            pq.push({cost+1, node+1});
            check[node+1] = true;
            parent[node+1] = node;
        }
        if(node*2 <= 100000 && !check[node*2]) {
            pq.push({cost+1, node*2});
            check[node*2] = true;
            parent[node*2] = node;
        }
    }
}

int main() {
    cin >> N >> K;
    
    dijkstra(N);
    
    cout << N << ' ';
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}