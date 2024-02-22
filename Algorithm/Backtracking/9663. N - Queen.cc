#include <iostream>
using namespace std;

int n, count = 0, col[15];

bool promising(int level) {
    for(int i = 0; i < level; i++) {
        if(col[level] == col[i]) return false;
        if((col[level] - (level-i)) == col[i]) return false;
        if((col[level] + (level-i)) == col[i]) return false;
    }
    
    return true;
}

void backtracking(int level, int row) {
    col[level] = row;
    
    if(level != n-1) {
        if(promising(level)) {
            for(int i = 0; i < n; i++) {
                backtracking(level + 1, i);
            }
        }
    } else {
        if(promising(level)) count++;
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        backtracking(0, i);
    }
    
    cout << count;
}
