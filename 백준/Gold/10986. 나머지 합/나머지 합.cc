#include <iostream>
using namespace std;

long long n, m, tmp, sum = 0, cnt = 0;
long long mod[1001] = {0,};

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        sum += tmp;
        mod[sum % m]++;
    }
    
    for(int i = 0; i < m; i++) {
        cnt += (mod[i] * (mod[i]-1)) / 2;
    }
    
    cout << mod[0] + cnt;
}