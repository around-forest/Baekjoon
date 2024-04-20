#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char map[25][25];
bool check[25][25] = {0, };
vector<int> result;

void dfs(int x, int y) {
    check[x][y] = true;
    cnt++;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(map[nx][ny] == '1' && check[nx][ny] == false) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == '1' && check[i][j] == false) {
                cnt = 0;
                dfs(i, j);
                result.push_back(cnt);
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    cout << result.size() << '\n';
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
}
