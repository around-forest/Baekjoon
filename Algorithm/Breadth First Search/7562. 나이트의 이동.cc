#include <iostream>
#include <queue>
using namespace std;

int T, I, sx, sy, tx, ty;
int chess[301][301];
bool check[301][301];
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {-2, -1, 2, 1, -2, -1, 2, 1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    
    chess[x][y] = 0;
    check[x][y] = true;
    
    q.push({x, y});
    
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        
        if(fx == tx && fy == ty) {
            cout << chess[tx][ty] << '\n';
            return;
        }
        
        for(int i = 0; i < 8; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            
            if(!check[nx][ny] && nx >= 0 && nx < I && ny >= 0 && ny < I) {
                q.push({nx, ny});
                check[nx][ny] = true;
                chess[nx][ny] = chess[fx][fy] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while(T--) {
        cin >> I;
        cin >> sx >> sy >> tx >> ty;
        
        bfs(sx, sy);
        
        for(int i = 0; i < I; i++) {
            for(int j = 0; j < I; j++) {
                check[i][j] = false;
                chess[i][j] = 0;
            }
        }
    }
}
