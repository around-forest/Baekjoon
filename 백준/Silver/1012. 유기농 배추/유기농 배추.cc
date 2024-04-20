#include <iostream>
#include <vector>
using namespace std;

int T, M, N, K, cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool field[51][51];
bool check[51][51];

void dfs(int y, int x) {
    check[y][x] = true;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if(field[ny][nx] == true && check[ny][nx] == false) {
                dfs(ny, nx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while(T--) {
        cin >> M >> N >> K;
        cnt = 0;
        
        while(K--) {
            int i, j;
            cin >> j >> i;
            field[i][j] = true;
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(field[i][j] == true && check[i][j] == false) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                field[i][j] = false;
                check[i][j] = false;
            }
        }
        
        cout << cnt << '\n';
    }
}