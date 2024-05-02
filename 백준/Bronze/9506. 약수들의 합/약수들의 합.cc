#include <iostream>
using namespace std;

int main(){
    while(1){
        int n, sum = 0;
        cin >> n;
        if(n == -1) break;
        for(int i = n-1; i > 0; i--){
            if(n % i == 0) sum += i;
        }
        if(sum == n){
            cout << n << " = 1";
            for(int i = 2; i < n; i++){
                if(n % i == 0) cout << " + " << i;
            }
        }
        else cout << n << " is NOT perfect.";
        cout << endl;
    }
}