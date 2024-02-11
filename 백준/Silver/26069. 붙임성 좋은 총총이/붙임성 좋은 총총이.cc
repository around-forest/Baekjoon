#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n, count = 0;
    string tmp1, tmp2;
    map<string, bool> name;
    
    cin >> n;
    
    while(n--) {
        cin >> tmp1 >> tmp2;
        
        if(name.find(tmp1) == name.end()) name.insert(make_pair(tmp1, false));
        if(name.find(tmp2) == name.end()) name.insert(make_pair(tmp2, false));
        
        if(tmp1 == "ChongChong" && name[tmp1] != true) {
            name[tmp1] = true;
            count++;
        }
        if(tmp2 == "ChongChong" && name[tmp2] != true) {
            name[tmp2] = true;
            count++;
        }
        
        if(name[tmp1] == true && name[tmp2] != true) {
            name[tmp2] = true;
            count++;
        } else if(name[tmp2] == true && name[tmp1] != true) {
            name[tmp1] = true;
            count++;
        }
    }
    
    cout << count;
}