#include <iostream>
#include <queue>
using namespace std;

int N, M;
int game[102] = {0, };
bool check[102];
queue<pair<int, int>> q;

void bfs(int x) {
    q.push(make_pair(x, 1));
    check[x];
    
    while(!q.empty()) {
        int dx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for(int i = 1; i <= 6; i++) {
            int nx = dx + i;
            
            if(nx == 100) {
                cout << cnt;
                return;
            } else if(nx < 100) {
                while(game[nx] != 0) {
                    nx = game[nx];
                }
                if(!check[nx]) {
                    q.push(make_pair(nx, cnt+1));
                    check[nx] = true;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        game[x] = y;
    }
    
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        game[x] = y;
    }
    
    bfs(1);
}
