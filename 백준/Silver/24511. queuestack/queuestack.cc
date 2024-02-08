#include <iostream>
using namespace std;

int main() {
    int n, m, tmp;
    int check[2][200001];
    cin >> n;
    
    for(int i = n-1; i >= 0; i--) {
        cin >> tmp;
        check[0][i] = tmp;
    }
    
    for(int i = n-1; i >= 0; i--) {
        cin >> tmp;
        check[1][i] = tmp;
    }
    
    cin >> m;
    
    for(int i = n; i < n+m; i++) {
        cin >> tmp;
        check[0][i] = 0;
        check[1][i] = tmp;
    }
    tmp = 0;
    for(int i = 0; tmp != m; i++) {
        if(check[0][i] == 0) {
            cout << check[1][i] << ' ';
            tmp++;
        }
    }
}