#include <iostream>
using namespace std;

int main() {
    int n, tmp1 = 0, tmp2 = 1, result = 0;
    
    cin >> n;
    
    if(n >= 2) {
        for(int i = 2; i <= n; i++) {
            result = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = result;
        }
        cout << result;
    } else if(n == 1) {
        cout << tmp2;
    } else if(n == 0) {
        cout << tmp1;
    }
}