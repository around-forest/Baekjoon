#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n, start, end, count = 1, tmp;
    vector<pair<int, int>> times;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        times.push_back(make_pair(end, start));
    }
    
    sort(times.begin(), times.end());
    
    tmp = times[0].first;
    
    for(int i = 1; i < n; i++) {
        if(times[i].second >= tmp) {
            tmp = times[i].first;
            count++;
        }
    }
    
    cout << count;
}
