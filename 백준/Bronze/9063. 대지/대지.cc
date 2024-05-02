#include <iostream>
using namespace std;

int main(){   
    int n, xmin, xmax, ymin, ymax;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(i == 0){
            xmax = x;
            xmin = x;
            ymax = y;
            ymin = y;
        }
        if(x > xmax) xmax = x;
        if(x < xmin) xmin = x;
        if(y > ymax) ymax = y;
        if(y < ymin) ymin = y;
    }
    cout << (xmax - xmin) * (ymax - ymin);
}