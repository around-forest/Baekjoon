#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n, m;
    string tmp;
    map<string, int> note;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        
        if(tmp.size() >= m) {
            if(note.find(tmp) == note.end()) {
                note.insert(make_pair(tmp, 1));
            } else {
                note[tmp]++;
            }
        }
    }
    
    vector<pair<string, int>> result(note.begin(), note.end());
    
    sort(result.begin(), result.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if(a.second != b.second) {
            return a.second > b.second;
        }
        
        else if(a.first.size() != b.first.size()) {
            return a.first.size() > b.first.size();
        }
        
        return a.first < b.first;
    });
    
    for(int i = 0; i < note.size(); i++) cout << result[i].first << '\n';
}
