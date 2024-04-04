#include <iostream>
using namespace std;

int M, N;
int map[501][501], dp[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int route(int x, int y) {
    if(x == M - 1 && y == N - 1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 0;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if(map[nx][ny] < map[x][y]) {
                dp[x][y] += route(nx, ny);
            }
        }
    }
    
    return dp[x][y];
}

int main() {
    cin >> M >> N;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << route(0, 0);
}
