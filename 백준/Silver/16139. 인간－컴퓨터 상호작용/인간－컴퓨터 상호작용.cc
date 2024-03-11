#include <iostream>
#include <string>
using namespace std;

char word;
int q, l, r;
int sum[26][2001] = {0,};
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> q;
    
    while(q--) {
        cin >> word >> l >> r;
        
        for(int i = 0; i <= r; i++) {
            if(sum[word-97][i]) {
                continue;
            } else {
                if(S[i] == word) sum[word-97][i] = sum[word-97][i-1] + 1;
                else sum[word-97][i] = sum[word-97][i-1];
            }
        }
        
        cout << sum[word-97][r] - sum[word-97][l-1] << '\n';
    }
}
