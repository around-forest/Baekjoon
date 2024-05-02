#include <iostream>
using namespace std;

int main(){
    int n, a, cnt = 0, check;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == 1) continue;
        check = 0;
        for(int j = 2; j < a; j++){
            if(a % j == 0) check = 1;
        }
        if(check == 0) cnt++;
    }
    cout << cnt;
}