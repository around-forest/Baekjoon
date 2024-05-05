#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, tmp;
    cin >> n;
    int a[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        } 
    }
    
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}