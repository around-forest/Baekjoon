#include <iostream>
using namespace std;

int main(){
    int x, y, w, h, xmin, ymin;
    cin >> x >> y >> w >> h;
    xmin = x;
    ymin = y;
    if(xmin > w-x) xmin = w-x;
    if(ymin > h-y) ymin = h-y;
    if(xmin > ymin) cout << ymin;
    else cout << xmin;
}