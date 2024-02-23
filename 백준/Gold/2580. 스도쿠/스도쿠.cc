#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool finished = false;
int sudoku[9][9];
int count = 0;
vector<pair<int, int>> zeros;
pair<int, int> tmp;

bool promising(int n) {
    for(int k = 0; k < 9; k++) {
        if(sudoku[zeros[n].first][zeros[n].second] == sudoku[zeros[n].first][k] && k != zeros[n].second) return false;
        if(sudoku[zeros[n].first][zeros[n].second] == sudoku[k][zeros[n].second] && k != zeros[n].first) return false;
    }
    
    for(int k = zeros[n].first / 3 * 3; k < zeros[n].first / 3 * 3 + 3; k++) {
        for(int l = zeros[n].second / 3 * 3; l < zeros[n].second / 3 * 3 + 3; l++) {
            if(sudoku[zeros[n].first][zeros[n].second] == sudoku[k][l] && k != zeros[n].first && l != zeros[n].second)
                return false;
        }
    }
    return true;
}

void backtracking(int n) {
    if(count != n) {
        for(int k = 1; k < 10; k++) {
            sudoku[zeros[n].first][zeros[n].second] = k;
            if(promising(n)) {
                backtracking(n+1);
            }
            if(finished) return;
        }
        sudoku[zeros[n].first][zeros[n].second] = 0;
    } else {
        finished = true;
        return;
    }
}

int main() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            
            if(sudoku[i][j] == 0) {
                count++;
                tmp.first = i;
                tmp.second = j;
                zeros.push_back(tmp);
            }
        }
    }
    
    backtracking(0);
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}