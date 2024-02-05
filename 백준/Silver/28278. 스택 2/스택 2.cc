#include <iostream>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, p, index = -1;
    int stack[1000001];
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> p;
        
        if(p == 1) {
            cin >> x;
            index++;
            stack[index] = x;
        } else if(p == 2) {
            if(index > -1) {
                cout << stack[index] << '\n';
                index--;
            } else {
                cout << index << '\n';
            }
        } else if(p == 3) {
            cout << index + 1 << '\n';
        } else if(p == 4) {
            if(index == -1) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            if(index > -1) {
                cout << stack[index] << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}