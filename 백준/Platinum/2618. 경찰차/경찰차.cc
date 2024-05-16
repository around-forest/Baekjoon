#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int N, W;
int dist[1001][1001];
vector<pair<int, int>> cases;

int dp(int cap1, int cap2) {
    if(cap1 == W || cap2 == W) return 0;
    if(dist[cap1][cap2] != -1) return dist[cap1][cap2];
    
    int nextCase = max(cap1, cap2) + 1;
    int dist1, dist2;
    
    if(cap1 == 0) dist1 = abs(1 - cases[nextCase].first) + abs(1 - cases[nextCase].second);
    else dist1 = abs(cases[cap1].first - cases[nextCase].first) + abs(cases[cap1].second - cases[nextCase].second);
    
    if(cap2 == 0) dist2 = abs(N - cases[nextCase].first) + abs(N - cases[nextCase].second);
    else dist2 = abs(cases[cap2].first - cases[nextCase].first) + abs(cases[cap2].second - cases[nextCase].second);
    
    int result1 = dist1 + dp(nextCase, cap2);
    int result2 = dist2 + dp(cap1, nextCase);
    
    dist[cap1][cap2] = min(result1, result2);
    return dist[cap1][cap2];
}

void route(int cap1, int cap2) {
    if(cap1 == W || cap2 == W) return;
    
    int nextCase = max(cap1, cap2) + 1;
    int dist1, dist2;
    
    if(cap1 == 0) dist1 = abs(1 - cases[nextCase].first) + abs(1 - cases[nextCase].second);
    else dist1 = abs(cases[cap1].first - cases[nextCase].first) + abs(cases[cap1].second - cases[nextCase].second);
    
    if(cap2 == 0) dist2 = abs(N - cases[nextCase].first) + abs(N - cases[nextCase].second);
    else dist2 = abs(cases[cap2].first - cases[nextCase].first) + abs(cases[cap2].second - cases[nextCase].second);
    
    int result1 = dist1 + dist[nextCase][cap2];
    int result2 = dist2 + dist[cap1][nextCase];
    
    if(result1 < result2) {
        cout << 1 << '\n';
        route(nextCase, cap2);
    } else {
        cout << 2 << '\n';
        route(cap1, nextCase);
    }
}

int main() {
    cin >> N >> W;
    
    cases.push_back(make_pair(0, 0));
    for(int i = 1; i <= W; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cases.push_back(make_pair(tmp1, tmp2));
    }
    
    memset(dist, -1, sizeof(dist));
    
    cout << dp(0, 0) << '\n';
    route(0, 0);
}