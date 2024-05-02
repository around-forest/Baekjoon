#include <iostream>
using namespace std;

int main(){
    int m, n, sum = 0, min = -1, check;
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        check = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0) check++;
        }
        if(check == 2){
            if(min == -1) min = i;
            sum += i;
        }
    }
    if(min == -1) cout << -1 << endl;
    else cout << sum << endl << min << endl;
}