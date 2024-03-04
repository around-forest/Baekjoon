#include <iostream>
#include <cmath>
using namespace std;

bool check[22];
int n, ans = 20000;
int stats[21][21];

void DFS(int count, int index) {
    if(count == n / 2) {
        int start = 0, link = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(check[i] == true && check[j] == true) start += stats[i][j];
                if(check[i] == false && check[j] == false) link += stats[i][j];
            }
        }
        
        int tmp = abs(start - link);
        if(tmp < ans) ans = tmp;
        return;
    }

    for(int i = index; i < n; i++) {
        check[i] = true;
        DFS(count + 1, i + 1);
        check[i] = false;
    }

}

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> stats[i][j];
        }
    }
    
    DFS(0, 1);
    
    cout << ans;
}
