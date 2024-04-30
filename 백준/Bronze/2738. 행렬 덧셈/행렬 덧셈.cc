#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, m, a[101][101], b[101][101], sum[101][101];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }
}