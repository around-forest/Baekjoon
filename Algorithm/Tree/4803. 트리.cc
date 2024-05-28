#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, caseNumb = 1, cnt = 0;
bool visited[502];
bool check;

void tree(int startNode, vector<int> graph[502], int prev) {
    visited[startNode] = true;
    for(int i = 0; i < graph[startNode].size(); i++) {
        if(graph[startNode][i] == prev) continue;
        if(visited[graph[startNode][i]]) {
            check = true;
            continue;
        }
        tree(graph[startNode][i], graph, startNode);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    while(n != 0 || m != 0) {
        vector<int> graph[502];
        
        for(int i = 0; i < m; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) check = false;
            
            tree(i, graph, 0);
            
            if(!check) cnt++;
        }
        
        if(cnt > 1) {
            cout << "Case " << caseNumb << ": A forest of " << cnt << " trees.\n";
        } else if(cnt == 1) {
            cout << "Case " << caseNumb << ": There is one tree.\n";
        } else {
            cout << "Case " << caseNumb << ": No trees.\n";
        }
        
        caseNumb++;
        cnt = 0;
        memset(visited, false, sizeof(visited));
        
        cin >> n >> m;
    }
}
