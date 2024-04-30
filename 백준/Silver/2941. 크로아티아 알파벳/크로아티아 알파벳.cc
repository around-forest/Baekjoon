#include <iostream>
#include <string>
using namespace std;

int main(){
    int cnt = 0;
    string str;
    cin >> str;
    
    for(int i = 0; i < str.length();){
        if(str[i] == 'c'  && str[i+1] == '='){
            cnt++;
            i += 2;
            continue;
        }
        else if(str[i] == 'c'  && str[i+1] == '-'){
            cnt++;
            i += 2;
            continue;
        }
        else if(str[i] == 'd'  && str[i+1] == 'z' && str[i+2] == '='){
            cnt++;
            i += 3;
            continue;
        }
        else if(str[i] == 'd'  && str[i+1] == '-'){
            cnt++;
            i += 2;
            continue;
        }
        else if(str[i] == 'l'  && str[i+1] == 'j'){
            cnt++;
            i += 2;
            continue;
        }
        else if(str[i] == 'n'  && str[i+1] == 'j'){
            cnt++;
            i += 2;
            continue;
        }
        else if(str[i] == 's'  && str[i+1] == '='){
            cnt++;
            i += 2;
            continue;
        }
        else if(str[i] == 'z'  && str[i+1] == '='){
            cnt++;
            i += 2;
            continue;
        }
        else{
            if(str[i] == NULL) break;
            cnt++;
            i++;
            continue;
        }
    }
    cout << cnt;
}