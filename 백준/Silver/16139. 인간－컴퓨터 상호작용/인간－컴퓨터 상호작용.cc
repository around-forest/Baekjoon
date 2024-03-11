#include <iostream>
#include <string>
using namespace std;

char word;
int q, l, r, count;
int sum[26][200001] = {0,};
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> q;
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < S.size(); j++) {
            if(S[j] == 'a' + i) sum[i][j] = sum[i][j-1] + 1;
            else sum[i][j] = sum[i][j-1];
        }
    }
    
    while(q--) {
        cin >> word >> l >> r;
        
        cout << sum[word-'a'][r] - sum[word-'a'][l-1] << '\n';
    }
}