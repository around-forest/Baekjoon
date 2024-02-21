#include <iostream>
using namespace std;

int main() {
    int n, k, max = -10000000, tmp;
    int array[100001] = {0,};
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        array[i] = array[i-1] + tmp;
    }
    for(int i = k; i <= n; i++) {
        if(array[i] - array[i-k] > max) max = array[i] - array[i-k];
    }
    
    cout << max;
}