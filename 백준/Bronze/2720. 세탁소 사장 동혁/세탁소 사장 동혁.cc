#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int t, c;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        cin >> c;
        
        cout << c / 25 << " ";
        cout << (c % 25) / 10 << " ";
        cout << ((c % 25) % 10) / 5 << " ";
        cout << (((c % 25) % 10) % 5) / 1 << endl;
    }
}