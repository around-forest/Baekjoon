#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int result = 0;
vector<pair<int, int>> points;

void input() {
    for(int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
}

void solution() {
    for(int i = 0; i < 2; i++) {
        int a = points[0].first, b = points[0].second;
        int c = points[i].first, d = points[i].second;
        int e = points[i+1].first, f = points[i+1].second;
        
        result += (a*d + c*f + e*b - b*c - d*e - f*a);
    }
}

int main() {
    input();
    solution();
    
    if(result > 0) cout << 1;
    else if(result < 0) cout << -1;
    else cout << 0;
}