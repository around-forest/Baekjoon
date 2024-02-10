#include <iostream>
using namespace std;

int main() {
    long long int n, m, t, answer, tmp;
    
    cin >> t;
    
    while(t--) {
        cin >> n >> m;
        answer = 1;
        tmp = 1;
       
        for(int i = m; i > m-n; i--) {
            answer *= i;
            answer /= tmp++;
        }
        
        cout << answer << '\n';
    }
}