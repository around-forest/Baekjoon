#include <iostream>
using namespace std;

int N, K, value;
int dp[100001] = {1, 0};

int main() {
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        cin >> value;
        
        for(int j = value; j <= K; j++) {
            dp[j] += dp[j - value];
        }
    }
    
    cout << dp[K];
}
