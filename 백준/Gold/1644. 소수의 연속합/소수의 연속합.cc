#include <iostream>
#include <vector>
using namespace std;

int N, count = 0;
vector<int> prime;

void eratos(int n) {
    vector<bool> tmp(n + 1, true);
    
    for(int i = 2; i*i <= n; i++) {
        if(tmp[i]) {
            for(int j = i*i; j <= n; j += i) {
                tmp[j] = false;
            }
        }
    }
    
    for(int i = 2; i <= n; i++) {
        if(tmp[i]) prime.push_back(i);
    }
}

int main() {
    cin >> N;
    
    if(N == 1) {
        cout << 0;
        return 0;
    }
    
    eratos(N);
    
    int left = 0, right = 0, sum = 0;
    
    while(left <= right) {
        if(sum > N) {
            sum -= prime[left++];
        } else if(sum < N) {
            sum += prime[right++];
        } else {
            count++;
            sum -= prime[left++];
        }
        
        if(right > prime.size()) break;
    }
    
    cout << count;
}