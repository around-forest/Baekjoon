#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, tmpInt, minCnt = 4000001;
int checker[2001][2001] = {0,};
char tmpChar;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> tmpChar;
            if(((i + j) % 2 == 0 && tmpChar != 'B') || ((i + j) % 2 != 0 && tmpChar == 'B')) {
                checker[i][j] = 1;
            }
            checker[i][j] += checker[i-1][j] + checker[i][j-1] - checker[i-1][j-1];
        }
    }
    
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            tmpInt = checker[i][j] - checker[i-k][j] - checker[i][j-k] + checker[i-k][j-k];
            tmpInt = min(k * k - tmpInt, tmpInt);
            minCnt = min(minCnt, tmpInt);
        }
    }
    
    cout << minCnt;
}