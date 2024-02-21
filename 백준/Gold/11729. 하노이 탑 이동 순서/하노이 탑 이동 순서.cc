#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int to) {
    int res;
    
    if(n == 1) cout << from << ' ' << to << '\n';
    else {
        res = 6 - from - to;
        hanoi(n-1, from, res);
        cout << from << ' ' << to << '\n';
        hanoi(n-1, res, to);
    }
}

int main() {
    int n, k;
    cin >> n;
    
    k =  pow(2,n) - 1;
    
    cout << k << '\n';
    hanoi(n, 1, 3);
}