#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, numerator, denominator;
    
    cin >> a >> b >> c >> d;
    
    // a/b , c/d
    numerator = (c*b) + (a*d);
    denominator = (b*d);
    
    if(numerator >= denominator) {
        for(int i = denominator; i > 0; i--) {
            if((numerator%i == 0) && (denominator%i == 0)) {
                cout << numerator/i << ' ' << denominator/i;
                break;
            }
        }
    } else {
        for(int i = numerator; i > 0; i--) {
            if((numerator%i == 0) && (denominator%i == 0)) {
                cout << numerator/i << ' ' << denominator/i;
                break;
            }
        }
    }
}