#include <iostream>
using namespace std;

int n, nCnt = 0, zCnt = 0, oCnt = 0;
int image[2187][2187];

void merge(int x, int y, int size) {
    int tmp = image[y][x];
    
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(tmp != image[i][j]) {
                tmp = size / 3;
                merge(x, y, tmp); // 0-3, 0-3
                merge(x + tmp, y, tmp); // 3-6, 0-3
                merge(x + tmp + tmp, y, tmp); // 6-9, 0-3
                merge(x, y + tmp, tmp); // 0-3, 3-6
                merge(x + tmp, y + tmp, tmp); // 3-6, 3-6
                merge(x + tmp + tmp, y + tmp, tmp); // 6-9, 3-6
                merge(x, y + tmp + tmp, tmp); // 0-3, 6-9
                merge(x + tmp, y + tmp + tmp, tmp); // 3-6, 6-9
                merge(x + tmp + tmp, y + tmp + tmp, tmp); // 6-9, 6-9
                
                return;
            }
        }
    }
    
    if(tmp == -1) nCnt++;
    else if(tmp == 0) zCnt++;
    else oCnt++;
    
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
    
    cout << nCnt << '\n' << zCnt << '\n' << oCnt;
}