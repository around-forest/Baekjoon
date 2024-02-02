#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    map<string, int> result;
    
    cin >> s;
    
    for(int i = 0; i < s.size(); i++) {
        for(int j = 1; j <= s.size()-i; j++) {
            result.insert(make_pair(s.substr(i, j), 0));
        }
    }
    
    cout << result.size();
}