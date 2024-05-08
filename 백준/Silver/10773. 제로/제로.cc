#include <iostream>
using namespace std;

int main() {
    int k, tmp, sum = 0, index = -1;
    int stack[100001];
    
    cin >> k;
    
    for(int i = 0; i < k; i++) {
        cin >> tmp;
        
        if(tmp == 0) {
            index--;
        } else {
            stack[++index] = tmp;
        }
    }
    
    for(int i = 0; i <= index; i++) {
        sum += stack[i];
    }
    
    cout << sum;
}