#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, cnt = 0, c = 1;
    string str;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str.length() == 1){
            cnt++;
            continue;
        }
        for(int j = 0; j < str.length()-2; j++){
            if(str[j] == str[j+1]) continue;
            for(int k = j+2; k < str.length(); k++){
                if(str[j] == str[k]){
                    c = 0;
                    break;
                }
            }
        }
        if(c == 1) cnt++;
        else c = 1;
    }
    cout << cnt;
}