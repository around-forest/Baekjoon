#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, power, sum, tenth, m, p = 1;
    
    cin >> n;
    for(int j = n; (j /= 10) != 0; ) p++;
    for(int i = n - 9 * p; i < n ; i++){
        m = i;
        sum = i % 10;
        power = 1;
        for(int j = i; (j /= 10) != 0; ) power++;
        tenth = pow(10, power);
        for(int j = 1; j <= power; j++){
            sum += (m / tenth);
            m %= tenth;
            tenth /= 10;
        }
        sum += i;
        if(sum == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;
}