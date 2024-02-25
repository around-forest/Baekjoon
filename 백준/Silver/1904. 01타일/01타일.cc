// boj 1904 01 타일
#include <iostream>
using namespace std;

int array[1000001];

int main() {
    int n;
    
    cin >> n;
    
    array[0] = 1;
    array[1] = 2;
    
    for(int i = 2; i < n; i++) {
        array[i] = (array[i-1] + array[i-2]) % 15746;
    }
    
    cout << array[n-1] % 15746;
}
