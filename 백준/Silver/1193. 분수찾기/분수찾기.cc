#include <iostream>
using namespace std;

int main(){
    int x, i, j = 1, num = 1;
    
    cin >> x;
    
    for(i = 0; ; i++){
        num += i;
        if(x < num) break;   
    }
    num = num-1;
    if(i % 2 ==  0){
        while(num-- != x){
            i--;
            j++;
        }
        cout << i << "/" << j;
    }
    else{
        while(num-- != x){
            i--;
            j++;
        }
        cout << j << "/" << i;
    }    
}