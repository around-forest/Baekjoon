#include <iostream>
#include <stack>
using namespace std;

int N, result = 0;
stack<pair<int, int>> line;

int main() {
    cin >> N;
    
    while(N--) {
        int tmp;
        int count = 1;
        cin >> tmp;
        
        while(!line.empty() && line.top().first <= tmp) {
            result += line.top().second;
            
            if(line.top().first == tmp) count += line.top().second;
            line.pop();
        }
        
        if(!line.empty()) result++;
        
        line.push(make_pair(tmp, count));
    }
    
    cout << result;
}
