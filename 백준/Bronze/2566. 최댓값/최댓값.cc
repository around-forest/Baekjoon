#include <iostream>
#include <string>
using namespace std;

int main(){
    int a[10][10], max = 0, n = 0, m = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(a[i][j] > max){
                max = a[i][j];
                n = i;
                m = j;
            }
        }
    }
    cout << max << "\n" << n+1 << " " << m+1;
}