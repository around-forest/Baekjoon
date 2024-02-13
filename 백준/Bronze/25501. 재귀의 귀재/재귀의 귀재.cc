#include <iostream>
#include <cstring>
using namespace std;

int count = 0;

int recursion(const char *s, int l, int r) {
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s) {
    return recursion(s, 0, strlen(s)-1);
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    char tmp[1001];
    
    cin >> t;
    
    while(t--) {
        cin >> tmp;
        
        cout << isPalindrome(tmp) << ' ' << count << '\n';
        count = 0;
    }
}