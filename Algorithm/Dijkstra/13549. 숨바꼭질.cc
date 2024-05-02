#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
bool check[100002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start) {
    pq.push({0, start});
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        check[node] = true;
        
        if(node == K) {
            cout << cost;
            break;
        }
        
        if(node-1 >= 0 && !check[node-1]) {
            pq.push({cost+1, node-1});
        }
        if(node+1 <= 100000 && !check[node+1]) {
            pq.push({cost+1, node+1});
        }
        if(node*2 <= 100000 && !check[node*2]) {
            pq.push({cost, node*2});
        }
    }
}

int main() {
    cin >> N >> K;
    
    dijkstra(N);
}
