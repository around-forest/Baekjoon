#include <iostream>
using namespace std;

int n, m, tmp, x1, y1, x2, y2, result;
int numb[1025][1025] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> tmp;
            numb[i][j] = numb[i][j-1] + tmp;
        }
    }
    
    for(int i = 1; i <= m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        result = 0;
        
        for(int j = x1; j <= x2; j++) {
            result += (numb[j][y2] - numb[j][y1-1]);
        }
        
        cout << result << '\n';
    }
}