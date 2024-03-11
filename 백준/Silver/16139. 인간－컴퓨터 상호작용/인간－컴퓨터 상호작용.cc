#include <iostream>
#include <string>
using namespace std;

char word;
int q, l, r, count;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> q;
    
    while(q--) {
        cin >> word >> l >> r;
        count = 0;
        
        for(int i = l; i <= r; i++) {
            if(S[i] == word) count++;
        }
        
        cout << count << '\n';
    }
}