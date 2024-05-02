#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    while(1){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        
        if(a > b && a > c) {
            if(a >= b+c){
                cout << "Invalid" << endl;
                continue;
            }
        }
        else if(b > a && b > c){
            if(b >= a+c){
                cout << "Invalid" << endl;
                continue;
            }
        }
        else if(c > b && c > a){
            if(c >= b+a){
                cout << "Invalid" << endl;
                continue;
            }
        }
        
        if(a == b && b== c) cout << "Equilateral" << endl;
        else if(a == b && b != c) cout << "Isosceles" << endl;
        else if(b == c && c != a) cout << "Isosceles" << endl;
        else if(c == a && a != b) cout << "Isosceles" << endl;
        else cout << "Scalene" << endl;
    }
}