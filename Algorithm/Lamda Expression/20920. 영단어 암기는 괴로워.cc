// 시간초과로 통과되지는 않지만, 람다 표현식을 사용하여 구현한 코드
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int n, m;
    string tmp;
    vector<pair<string, int>> note;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        
        if(tmp.size() >= m) {
            auto it = find_if(note.begin(), note.end(), [&tmp](const pair<string, int>& element) {
                return element.first == tmp;
            });
            
            if(it == note.end()) {
                note.push_back(make_pair(tmp, 1));
            } else {
                it->second++;
            }
        }
    }
    
    sort(note.begin(), note.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if(a.second != b.second) {
            return a.second > b.second;
        }
        
        if(a.first != b.first) {
            return a.first.size() > b.first.size();
        }
        
        return a.first < b.first;
    });
    
    for(int i = 0; i < note.size(); i++) cout << note[i].first << ' ';
}
