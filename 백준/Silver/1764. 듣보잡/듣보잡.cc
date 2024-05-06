#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m, count = 0;
    string tmp;
    map<string, int> name;
    vector<string> result;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        name.insert(make_pair(tmp, 0));
    }
    
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        if(name.count(tmp) == 1) {
            name[tmp] += 1;
            count++;
        } else { 
            name.insert(make_pair(tmp, 0));
        }
    }
    
    cout << count << '\n';
    
    for(auto i = name.begin(); i != name.end(); i++) {
        if(i->second > 0) {
            result.push_back(i->first);
        }
    }
    
    for(int i = 0; i < count; i++) {
        cout << result[i] << '\n';
    }
}