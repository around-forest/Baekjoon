#include <iostream>
using namespace std;

int n;
char image[64][64];

void merge(int x, int y, int size) {
    char tmp = image[y][x];
    
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(tmp != image[i][j]) {
                cout << '(';
                
                merge(x, y, size / 2);
                merge(x + size / 2, y, size / 2);
                merge(x, y + size / 2, size / 2);
                merge(x + size / 2, y + size / 2, size / 2);
                
                cout << ')';
                return;
            }
        }
    }
    
    if(tmp == '1') {
        cout << '1';
    } else {
        cout << '0';
    }
    
    return;
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }
    
    merge(0, 0, n);
    
}