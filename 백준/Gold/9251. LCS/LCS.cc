#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int length = 0;
int DP[1001][1001] = {0, };

int main() {
    cin >> a >> b;
    
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < a.size(); j++) {
            if(b[i] == a[j]) DP[i+1][j+1] = DP[i][j] + 1;
            else DP[i+1][j+1] = max(DP[i][j+1], DP[i+1][j]);
        }
    }
    
    for(int i = 0; i <= a.size(); i++) {
        if(DP[b.size()][i] > length) length = DP[b.size()][i];
    }
    
    cout << length;
}