#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, tmp1, tmp2, length = 0;
int series[101];
vector<pair<int, int>> lines;

bool compare1(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> tmp1 >> tmp2;
        
        lines.push_back(make_pair(tmp1, tmp2));
    }
    
    sort(lines.begin(), lines.end(), compare1);
    
    for(int i = 0; i < n; i++) {
        series[i] = 1;
        
        for(int j = i-1; j >= 0; j--) {
            if(lines[i].second > lines[j].second && (series[j] + 1) > series[i]) {
                series[i] = series[j] + 1;
            }
        }
        
        if(series[i] > length) length = series[i];
    }
    
    cout << n - length;
}
