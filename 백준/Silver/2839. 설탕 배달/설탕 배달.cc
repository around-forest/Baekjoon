#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, amount, cnt = 0;
    cin >> n;
    amount = n;
    
    if(amount%5 == 0){
        cnt = amount / 5;
    }
    else{
        do{
            amount -= 3;
            cnt++;
            if(amount <= 0){
                break;
            }
        }while(amount%5 != 0);
        
        if(amount >= 0){
            cnt += amount / 5;
        }
        else if(amount < 0) cnt = -1;
    }
    
    cout << cnt;
}