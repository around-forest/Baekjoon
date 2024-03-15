#include <iostream>
#include <string>
using namespace std;

int result = 0;
string eq, numb;
bool isMinus = false;

int main() {
    cin >> eq;
    
    for(int i = 0; i <= eq.size(); i++) {
        if(eq[i] == '-' || eq[i] == '+' || i == eq.size()) {
            if(isMinus) {
                result -= stoi(numb);
                numb = "";
            } else {
                result += stoi(numb);
                numb = "";
            }
        } else {
            numb += eq[i];
        }
        
        if(eq[i] == '-') {
            isMinus = true;
        }
    }
    
    cout << result;
}
