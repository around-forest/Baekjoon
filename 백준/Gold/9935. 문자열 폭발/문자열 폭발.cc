#include <iostream>
#include <string>
using namespace std;

string input;
string boom;
string tmp = "";

int main() {
    cin >> input >> boom;
    
    for(int i = 0; i < input.length(); i++) {
        tmp += input[i];
        
        if(tmp.length() >= boom.length()) {
            bool check = true;
            
            for(int j = 0; j < boom.length(); j++) {
                if(tmp[tmp.length() - boom.length() + j] != boom[j]) {
                    check = false;
                    break;
                }
            }
            
            if(check) {
                tmp.erase(tmp.end() - boom.length(), tmp.end());
            }
        }
    }
    
    if(tmp.empty()) cout << "FRULA";
    else cout << tmp;
}