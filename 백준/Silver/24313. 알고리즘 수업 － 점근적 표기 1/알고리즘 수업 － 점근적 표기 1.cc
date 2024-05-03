#include <iostream>
using namespace std;

int main(){
    int fn, gn, a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;
    
    fn = a1 * n0 + a0;
    gn = n0;
    if(fn <= c * gn && a1 <= c) cout << 1;
    else cout << 0;
}