#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, R, cnt = 0;
int result[100001];
vector<int> graph[100001];
bool check[100001];

void dfs(int r) {
    if(check[r]) return;
    
    check[r] = true;
    cnt++;
    result[r] = cnt;
    
    for(int i = 0; i < graph[r].size(); i++) {
        dfs(graph[r][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
    
    dfs(R);
    
    for(int i = 1; i <= N; i++) {
        cout << result[i] << '\n';
    }
}
