#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, tmp;
    string command;
    queue<int> que;
    
    cin >> n;
    
    while(n--) {
        cin >> command;
        
        if(command == "push") {
            cin >> tmp;
            que.push(tmp);
        } else if(command == "pop") {
            if(!que.empty()) {
                cout << que.front() << '\n';
                que.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if(command == "size") {
            cout << que.size() << '\n';
        } else if(command == "empty") {
            if(que.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if(command == "front") {
            if(!que.empty()) {
                cout << que.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if(command == "back") {
            if(!que.empty()) {
                cout << que.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}