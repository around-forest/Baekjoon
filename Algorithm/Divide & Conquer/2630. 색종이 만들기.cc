#include <iostream>
using namespace std;

int n, whiteCount = 0, blueCount = 0;
int paper[128][128];

void merge(int x, int y, int size) {
    int tmp = paper[y][x];
    bool check = false;
   
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(tmp != paper[i][j]) check = true;
            
            if(check) {
                merge(x, y, size / 2);
                merge(x, y + size / 2, size / 2);
                merge(x + size / 2, y, size / 2);
                merge(x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    }

    if(tmp == 0) whiteCount++;
    else blueCount++;
    
    return;
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    
    merge(0, 0, n);
    
    cout << whiteCount << '\n' << blueCount;
}
