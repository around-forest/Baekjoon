#include <iostream>
#include <stack>
using namespace std;

int main() {
    bool result = true;
    int n, tmp, numb = 1;
    stack<int> stack;
    
    cin >> n;
    
    while(n--) {
        cin >> tmp;
        
        if(tmp != numb) {
            stack.push(tmp);
        } else {
            numb++;
        }
        
        while(!stack.empty() && stack.top() == numb) {
            stack.pop();
            numb++;
        }
    }
    
    if(stack.empty()) cout << "Nice";
    else cout << "Sad";
}