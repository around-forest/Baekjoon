#include <iostream>
using namespace std;

int tmp[21][21][21] = {0,};

int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if(tmp[a][b][c]) return tmp[a][b][c];
    if(a < b && b < c) {
        tmp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    tmp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return tmp[a][b][c];
}

int main() {
    int a = 0, b = 0, c = 0;
    
    while(1) {
        cin >> a >> b >> c;
        
        if(a == -1 && b == -1 && c == -1) break;
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}