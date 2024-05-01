#include <iostream>
using namespace std;

int main(){
    int n, cnt = 1, i = 0;
    
    cin >> n;
    
    for(;;i++){
        cnt += (6 * i);
        if(n <= cnt){
            cout << i+1;
            break;
        }
    }
}