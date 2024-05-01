#include <iostream>
using namespace std;

int pow(int x, int n){
    int result = 1;
    while(n--) result *= x;
    return result;
}

int main(){
    int n;
    
    cin >> n;
    cout << pow(pow(2, n) + 1, 2);
}