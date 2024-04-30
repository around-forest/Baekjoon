#include <iostream>
#include <string>
using namespace std;

int board[100][101] = {0 ,};

int main(){
    int n = 0, area = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        for(int j = x; j < x + 10; j++){
            for(int k = y; k < y + 10; k++){
                board[k][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(board[j][i] == 1) area++;
        }
    }
    
    cout << area;
}