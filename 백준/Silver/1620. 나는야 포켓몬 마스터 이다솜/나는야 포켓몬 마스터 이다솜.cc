#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    map<string, int> pokemon;
    vector<string> name;
    int n, m;
    string tmp;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        name.push_back(tmp);
        pokemon.insert(make_pair(tmp, i));
    }
    
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        
        if(tmp[0] < 65){
            cout << name[stoi(tmp)-1] << '\n';
        } else {
            cout << pokemon[tmp]+1 << '\n';
        }
    }
    
    return 0;
}