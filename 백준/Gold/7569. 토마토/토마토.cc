#include <iostream>
#include <queue>
using namespace std;

int M, N, H, day = -1;
int box[10001][101];
bool check[10001][101];

queue<pair<int, int>> q;
queue<pair<int, int>> tmp;

void bfs() {
    int dx[] = {1, -1, 0, 0, -N, N};
    int dy[] = {0, 0, 1, -1, 0, 0};
    
    while(!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        
        for(int i = 0; i < 6; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            
            if((i < 4 && nx >= (fx/N)*N && nx < (fx/N+1)*N) || (i >= 4 && nx >= 0 && nx < N*H)) {
                if(ny >= 0 && ny < M) {
                    if(check[nx][ny] == false && box[nx][ny] == 0) {
                        box[nx][ny] = 1;
                        check[nx][ny] = true;
                        tmp.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;
    
    for(int i = 0; i < N*H; i++) {
        for(int j = 0; j < M; j++) {
            cin >> box[i][j];
            
            if(box[i][j] == 1) {
                q.push({i, j});
                check[i][j] = true;
            }
        }
    }
    
    while(!q.empty()) {
        day++;
        bfs();
        
        while(!tmp.empty()) {
            q.push({tmp.front().first, tmp.front().second});
            tmp.pop();
        }
    }
    
    for(int i = 0; i < N*H; i++) {
        for(int j = 0; j < M; j++) {
            if(box[i][j] == 0) {
                day = -1;
                break;
            }
        }
        if(day == -1) break;
    }
    
    cout << day;
}