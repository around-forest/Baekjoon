#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, tmp, command;
    list<int> list;
    
    cin >> n;
    
    while(n--) {
        cin >> command;
        
        if(command == 1) {
            cin >> tmp;
            list.push_front(tmp);
        } else if(command == 2) {
            cin >> tmp;
            list.push_back(tmp);
        } else if(command == 3) {
            if(!list.empty()) {
                cout << list.front() << '\n';
                list.pop_front();
            } else {
                cout << -1 << '\n';
            }
        } else if(command == 4) {
            if(!list.empty()) {
                cout << list.back() << '\n';
                list.pop_back();
            } else {
                cout << -1 << '\n';
            }
        } else if(command == 5) {
            cout << list.size() << '\n';
        } else if(command == 6) {
            if(!list.empty()) {
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        } else if(command == 7) {
            if(!list.empty()) {
                cout << list.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if(command == 8) {
            if(!list.empty()) {
                cout << list.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}