#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n[6], tmp, sum = 0;
    for(int i = 0; i < 5; i++){
        cin >> n[i];
        sum += n[i];
    }
    
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 5; j++){
            if(n[i] > n[j]){
                tmp = n[i];
                n[i] = n[j];
                n[j] = tmp;
            }    
        }
    }
    cout << sum / 5 << endl << n[2];
}