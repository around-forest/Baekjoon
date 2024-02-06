#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    while(1) {
        bool result = true;
        int j = -1;
        string tmp;
        vector<char> stack;
        
        getline(cin, tmp, '\n');
        
        for(int i = 0; i < tmp.size(); i++) {
            if(tmp[i] == '(') {
                stack.push_back(tmp[i]);
                j++;
            }
            else if(tmp[i] == '[') {
                stack.push_back(tmp[i]);
                j++;
            }
            
            if(tmp[i] == ')') {
                if(j < 0) {
                    result = false;
                    break;
                } else if(stack[j] != '(') {
                    result = false;
                    break;
                }
                stack.erase(stack.begin() + j);
                j--;
            }
            else if(tmp[i] == ']') {
                if(j < 0) {
                    result = false;
                    break;
                } else if(stack[j] != '[') {
                    result = false;
                    break;
                }
                stack.erase(stack.begin() + j);
                j--;
            }
            
            if(i != 0 && tmp[i] == '.') break;
            else if(i == 0 && tmp[i] == '.') return 0;
        }
        
        if(j != -1) result = false;
        
        if(result) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}