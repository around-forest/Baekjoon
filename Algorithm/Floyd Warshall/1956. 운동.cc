#include <iostream>
#include <algorithm>

#define INF 1e9
using namespace std;

int V, E;
int path[401][401];
bool check[401];

void floydWarshall() {
    for(int k = 1; k <= V; k++) {
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
}

int cycle() {
    int result = INF;
    
    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            if(i == j) continue;
            result = min(result, path[i][j] + path[j][i]);
        }
    }
    
    if(result == INF) return -1;
    else return result;
}

int main() {
    cin >> V >> E;
    
    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            if(i == j) path[i][j] = 0;
            else path[i][j] = INF;
        }
    }
    
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        path[a][b] = c;
    }
    
    floydWarshall();
    
    cout << cycle();
}
