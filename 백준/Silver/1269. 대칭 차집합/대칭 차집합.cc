#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m, tmp;
    map<int, int> A, B, result;
    vector<int> tmpA, tmpB;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        A.insert(make_pair(tmp,tmp));
        tmpA.push_back(tmp);
    }
    
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        B.insert(make_pair(tmp,tmp));
        tmpB.push_back(tmp);
    }
    
    //A-B
    for(int i = 0; i < m; i++) {
        //if not exist
        if(A.find(tmpB[i]) == A.end()) {
            result.insert(make_pair(tmpB[i], tmpB[i]));
        }
    }
    
    //B-A
    for(int i = 0; i < n; i++) {
        //if not exist
        if(B.find(tmpA[i]) == B.end()) {
            result.insert(make_pair(tmpA[i], tmpA[i]));
        }
    }
    
    cout << result.size();
}