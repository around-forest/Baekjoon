#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c, d, e, f, x = 0, y = 0;
    cin >> a >> b >> c >> d >> e >> f;
    if(b != 0){
        x = (e * c - b * f) / (a * e - d * b);
        y = (c - a * x) / b;
    }
    else{
        x = (e * c - b * f) / (a * e - d * b);
        y = (f - d * x) / e;
    }
    cout << x << " " << y;
}