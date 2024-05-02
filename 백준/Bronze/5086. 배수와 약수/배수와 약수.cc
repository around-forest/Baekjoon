#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(1){
        int factor = 0, multiple = 0;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        if(b > a){
            if(b / a > 0 && b % a == 0) cout << "factor" << endl;
            else cout << "neither" << endl;
        }
        if(a > b){
            if(a / b > 0 && a % b == 0) cout << "multiple" << endl;
            else cout << "neither" << endl;
        }
    }
}