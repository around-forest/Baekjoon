#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long double area = 0;
vector<pair<long long, long long>> points;

void input() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
}

void getArea() {
    for(int i = 0; i < N - 1; i++) {
        long double a = points[0].first, b = points[0].second;
        long double c = points[i].first, d = points[i].second;
        long double e = points[i+1].first, f = points[i+1].second;
        
        area += (a * d + c * f + e * b - b * c - d * e - f * a) / 2;
    }
}

int main() {
    input();
    getArea();
    
    cout << fixed;
    cout.precision(1);
    cout << abs(area);
}
