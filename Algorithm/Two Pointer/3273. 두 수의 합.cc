#include <iostream>
#include <algorithm>
using namespace std;

int n, x, sum = 0;
int numb[100001];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> numb[i];
    }
    
    cin >> x;
    
    sort(numb, numb + n);
    
    int left = 0, right = n - 1;
    
    while(left < right) {
        if(numb[left] + numb[right] == x) {
            sum += 1;
            left += 1;
            right -= 1;
        } else if(numb[left] + numb[right] > x) {
            right -= 1;
        } else {
            left += 1;
        }
    }
    
    cout << sum;
}
