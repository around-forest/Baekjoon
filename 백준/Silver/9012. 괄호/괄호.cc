#include <iostream>
#include <string>
using namespace std;

int main() {
    int t, check;
    string tmp;
    
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> tmp;
        check = 0;
        
        for(int j = 0; j < tmp.size(); j++) {
            if(tmp[j] == '(') check++;
            else if(tmp[j] == ')') check--;
            
            if(check < 0) break;
        }
        
        if(check == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}