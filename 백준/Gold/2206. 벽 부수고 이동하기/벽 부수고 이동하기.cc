#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1002][1002];
int dist[1002][1002][2];
queue<pair<pair<int, int>, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs() {
    dist[1][1][0] = 1;
    q.push({{1, 1}, 0});
    
    while(!q.empty()) {
        int fx = q.front().first.first;
        int fy = q.front().first.second;
        int check = q.front().second;
        q.pop();
        
        if(fx == N && fy == M) {
            cout << dist[N][M][check];
            return;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                if(map[nx][ny] == 0 && dist[nx][ny][check] == 0) {
                    dist[nx][ny][check] = dist[fx][fy][check] + 1;
                    q.push({{nx, ny}, check});
                } else if(map[nx][ny] == 1 && check == 0) {
                    dist[nx][ny][check+1] = dist[fx][fy][check] + 1;
                    q.push({{nx, ny}, check+1});
                }
            }
        }
    }
    cout << -1;
}

int main() {
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp - '0';
        }
    }
    
    bfs();
}