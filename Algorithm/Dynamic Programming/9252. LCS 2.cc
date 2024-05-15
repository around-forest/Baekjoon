#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int maxLen = 0;
string a, b;
int arr[1002][1002];
vector<char> subsequence;

void dp(int x, int y) {
    if(arr[x][y] == 0) return;
    
    if(arr[x-1][y] == arr[x][y]) dp(x-1, y);
    else if(arr[x][y-1] == arr[x][y]) dp(x, y-1);
    else {
        subsequence.push_back(a[x-1]);
        dp(x-1, y-1);
    }
}

int main() {
    cin >> a >> b;
    
    for(int i = 0; i <= a.size(); i++) {
        for(int j = 0; j <= b.size(); j++) {
            if(i == 0 || j == 0) arr[i][j] = 0;
            else if(a[i-1] == b[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            
            if(arr[i][j] > maxLen) maxLen = arr[i][j];
        }
    }
    
    dp(a.size(), b.size());
    
    cout << maxLen << '\n';
    for(int i = subsequence.size() - 1; i >= 0; i--) {
        cout << subsequence[i];
    }
}
