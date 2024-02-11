#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n, count = 0;
    string tmp;
    map<string, int> user;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        
        if(tmp != "ENTER") {
            user.insert(make_pair(tmp, i));
        } else {
            count += user.size();
            user.clear();
        }
    }
    
    count += user.size();
    
    cout << count;
}