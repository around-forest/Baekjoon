#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;
int arr[31];
long long cnt;
vector<long long> tmp1, tmp2;

void dfs(vector<long long> &v, int start, int end, long long sum) {
    if(start > end) {
        v.push_back(sum);
        return;
    }
    
    dfs(v, start+1, end, sum);
    dfs(v, start+1, end, sum + arr[start]);
}

int main() {
    cin >> N >> C;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    dfs(tmp1, 0, N/2-1, 0);
    dfs(tmp2, N/2, N-1, 0);
    
    sort(tmp2.begin(), tmp2.end());
    
    for(int i = 0; i < tmp1.size(); i++) {
        long long x = C - tmp1[i]; // 가방 무게 - tmp1 모든 무게 = 남은 무게
        cnt += upper_bound(tmp2.begin(), tmp2.end(), x) - tmp2.begin();
    }
    
    cout << cnt;
}