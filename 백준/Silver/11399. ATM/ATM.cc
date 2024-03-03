#include <iostream>
#include <algorithm>
using namespace std;

int n, sum = 0;
int line[1001], times[1001] = {0,}; 

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> line[i];
    }
    
    sort(line, line + n);
    
    for(int i = 0; i < n; i++) {
        times[i] += (times[i-1] + line[i]);
    }
    
    for(int i = 0; i < n; i++) sum += times[i];
    
    cout << sum;
}
