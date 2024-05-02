#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c) cout << a + b + c;
    else if(a > b && a > c){
        if(a < b + c) cout << a + b + c;
        else cout << b + c + (b + c - 1);
    }
    else if(b > a && b > c){
        if(b < a + c) cout << a + b + c;
        else cout << a + c + (a + c - 1);
    }
    else if(c > b && c > a){
        if(c < b + a) cout << a + b + c;
        else cout << b + a + (b + a - 1);
    }
    else if(a == b && b > c) cout << a + b + c;
    else if(a == c && c > b) cout << a + b + c;
    else if(c == b && b > a) cout << a + b + c;
}