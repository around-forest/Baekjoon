#include <iostream>
using namespace std;

int main() {
    long long int n, result = 1;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) result *= i;
    
    cout << result;
}