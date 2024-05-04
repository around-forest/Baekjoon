#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int substring(string numb){
    for(int i = 0; i <= numb.length()-2; i++){
        if(numb[i] == '6'){
            if(numb[i+1] == '6' && numb[i+2] == '6') return 1;
        }
    }
    return 0;
}

int main(){
    int n, cnt = 0;
    cin >> n;
    
    for(int i = 666; ; i++){
        string numb;
        numb = to_string(i);
        if(substring(numb) != 0) cnt++;
        if(cnt == n){
            cout << i;
            break;
        } 
    }
}