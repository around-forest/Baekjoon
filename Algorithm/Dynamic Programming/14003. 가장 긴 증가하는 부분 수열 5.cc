#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, cnt = 0;
int series[1000001];
int dp[1000001];
vector<int> tmp, result;

int main() {
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> series[i];
    }
    tmp.push_back(series[1]);
    
    for(int i = 2; i <= N; i++) {
        if(tmp[cnt] < series[i]) {
            tmp.push_back(series[i]);
            cnt++;
            dp[i] = cnt;
        } else {
            int index = lower_bound(tmp.begin(), tmp.end(), series[i]) - tmp.begin();
            tmp[index] = series[i];
            dp[i] = index;
        }
    }
    
    for(int i = N; i >= 0; i--) {
        if(dp[i] == cnt) {
            result.push_back(series[i]);
            cnt--;
        }
    }
    
    cout << result.size() << '\n';
    for(int i = result.size() - 1; i >= 0; i--) cout << result[i] << ' ';
}
