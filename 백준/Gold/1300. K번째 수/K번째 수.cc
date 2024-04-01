#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, low, high, mid;

int main() {
    cin >> N >> K;
    
    K = min((long long)1000000000, K);
    low = 1;
    high = N * N;
    
    while(low <= high) {
        long long tmpCnt = 0;
        mid = (low + high) / 2;
        
        for(int i = 1; i <= N; i++) tmpCnt += min(mid / i, N);
        
        if(tmpCnt >= K) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
}