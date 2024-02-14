#include <iostream>
#include <cmath>
using namespace std;

void cantor(int n) {
    int l = pow(3, n-1);
    
    if(n == 0) cout << '-';
    else {
        if(n == 1) cout << '-';
        else cantor(n-1);
        for(int i = 0; i < l; i++) cout << ' ';
        if(n == 1) cout << '-';
        else cantor(n-1);
    }
}

int main() {
    int n;
    
    while(cin >> n) {
        cantor(n);
        cout << '\n';
    }
}
