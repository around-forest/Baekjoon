#include <iostream>
#include <queue>
using namespace std;

int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dist[101][101];
char graph[101][101];
bool check[101][101]; 

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    dist[x][y] = 1;
    
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                if(check[nx][ny] == false && graph[nx][ny] == '1') {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    dist[nx][ny] = dist[fx][fy] + 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }
    
    bfs(1, 1);
    
    cout << dist[N][M];
}
