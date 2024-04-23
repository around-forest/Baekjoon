#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool check[100001];
queue<pair<int, int>> q;

void bfs(int r) {
    q.push(make_pair(r, 0));
    check[r] = true;
    
    while(!q.empty()) {
        int point = q.front().first;
        int time = q.front().second;
        
        if(point == K) {
            return;
        }
        q.pop();
        
        if(point + 1 >= 0 && point + 1 < 100001 && !check[point + 1]) {
            check[point + 1] = true;
            q.push(make_pair(point + 1, time + 1));
        }
        if(point - 1 >= 0 && point - 1 < 100001 && !check[point - 1]) {
            check[point - 1] = true;
            q.push(make_pair(point - 1, time + 1));
        }
        if(point * 2 >= 0 && point * 2 < 100001 && !check[point * 2]) {
            check[point * 2] = true;
            q.push(make_pair(point * 2, time + 1));
        }
    }
}

int main() {
    cin >> N >> K;
    
    bfs(N);
    
    cout << q.front().second;
}
