#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, minDist = 0;
int map[11][11];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

int parents[11];
int height[11];
vector<pair<int, pair<int, int>>> graph;

void bfs(int y, int x, int num) {
    q.push({y, x});
    map[y][x] = num;
    
    while(!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int fy = ny + dy[i];
            int fx = nx + dx[i];
            
            if(fx < 0 || fx >= M || fy < 0 || fy >= N) continue;
            if(map[fy][fx] == -1) {
                map[fy][fx] = num;
                q.push({fy, fx});
            }
        }
    }
}

void bridge(int y, int x, int idx) {
    int dist = 0;
    int ny = y;
    int nx = x;
    
    while(1) {
        ny += dy[idx];
        nx += dx[idx];
        
        if(nx < 0 || nx >= M || ny < 0 || ny >= N || map[ny][nx] == map[y][x]) return;
        if(map[ny][nx] == 0) {
            dist++;
        } else {
            if(dist >= 2) graph.push_back({dist, {map[y][x], map[ny][nx]}});
            
            return;
        }
    }
}

int find(int k) {
    if(k == parents[k]) return k;
    return parents[k] = find(parents[k]);
}

bool unionFind(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) return false;
    
    if(height[u] > height[v]) swap(u, v);
    parents[u] = v;
    if(height[u] == height[v]) height[v]++;
    
    return true;
}

void reset() {
    for(int i = 0; i < 7; i++) {
        parents[i] = i;
        height[i] = 1;
    }
}

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    }
    
    int num = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == -1) {
                bfs(i, j, num);
                num++;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 4; k++) {
                if(map[i][j] != 0) bridge(i, j, k);
            }
        }
    }
    
    sort(graph.begin(), graph.end());
    reset();
    
    for(int i = 0; i < graph.size(); i++) {
        if(unionFind(graph[i].second.first, graph[i].second.second)) {
            minDist += graph[i].first;
        }
    }
    
    int check = find(1);
    for(int i = 2; i < num; i++) {
        if(find(i) != check) minDist = -1;
    }
    
    cout << minDist;
}