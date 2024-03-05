#include <iostream>
using namespace std;

int n, count = 0;
int tmp[101][10] = {0,};

void DP(int x) {
    for(int i = 0; i <= 9; i++) {
        if(i == 0) tmp[x][0] += tmp[x-1][i + 1];
        else if(i == 9) tmp[x][9] += tmp[x-1][i - 1];
        else {
            tmp[x][i] = tmp[x-1][i-1] + tmp[x-1][i+1];
        }
        
        tmp[x][i] %= 1000000000;
    }
}

int main() {
    cin >> n;
    
    for(int i = 1; i <= 9; i++) {
        tmp[1][i] = 1;
    }
    
    for(int i = 2; i <= n; i++) {
        DP(i);
    }
    
    for(int i = 0; i <= 9; i++) {
        count = (count + tmp[n][i]) % 1000000000;
    }
    
    cout << count;
    
}