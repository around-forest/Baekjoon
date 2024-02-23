#include <iostream>
using namespace std;

void divideConquer(int i, int j, int n) {
    if((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << ' ';
    } else {
        if(n / 3 == 0) cout << '*';
        else divideConquer(i, j, n / 3);
    }
}

int main() {
    int n;
    
    cin >> n;
    
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            divideConquer(i, j, n);
        }
        cout << '\n';
    }
}
