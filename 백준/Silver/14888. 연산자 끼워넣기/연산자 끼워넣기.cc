#include <iostream>
using namespace std;

int n, maxResult = -1000000000, minResult = 1000000000;
int operands[11], operators[4];

void backtracking(int result, int index) {
    if(index == n) {
        if(result > maxResult) maxResult = result;
        if(result < minResult) minResult = result;
        return;
    } else {
        for(int i = 0; i < 4; i++) {
            if(operators[i] > 0) {
                operators[i]--;
                if(i == 0) backtracking(result + operands[index], index + 1);
                else if(i == 1) backtracking(result - operands[index], index + 1);
                else if(i == 2) backtracking(result * operands[index], index + 1);
                else if(i == 3) backtracking(result / operands[index], index + 1);
                operators[i]++;
            }
        }
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> operands[i];
    for(int i = 0; i < 4; i++) cin >> operators[i];
    
    backtracking(operands[0], 1);
    
    cout << maxResult << '\n' << minResult;
    
}