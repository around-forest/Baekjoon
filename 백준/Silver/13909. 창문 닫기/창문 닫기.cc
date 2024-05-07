#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    
    cin >> n;
    
    // 약수의 개수가 짝수면 0 홀수면 1 즉, 제곱수에 해당하는 창문만 열려있음
    for(int i = 1; i*i <= n; i++) {
        count++;
    }
    
    cout << count;
}