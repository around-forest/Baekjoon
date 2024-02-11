#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    bool check = false;
    double n, tmp, sum = 0, min, max, count = 1;
    vector<double> vnum;
    vector<double> tnum;
    map<double, double> mnum;
    
    cin >> n;
    cin >> tmp;
    min = tmp;
    max = tmp;
    vnum.push_back(tmp);
    mnum.insert(make_pair(tmp,1));
    sum += tmp;
    
    for(int i = 0; i < n-1; i++) {
        cin >> tmp;
        
        vnum.push_back(tmp);
        sum += tmp;
        
        
        if(mnum.find(tmp) == mnum.end()) mnum.insert(make_pair(tmp, 1));
        else mnum[tmp]++;
        
        if(tmp > max) max = tmp;
        if(tmp < min) min = tmp;
    }
    
    cout << (int)floor(sum / n + 0.5) << '\n';
    
    sort(vnum.begin(), vnum.end());
    cout << (int)vnum[n/2] << '\n';
    
    for(int i = 0; i < n; i++) {
        if(mnum[vnum[i]] > count) {
            count = mnum[vnum[i]];
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(mnum[vnum[i]] == count && find(tnum.begin(), tnum.end(), vnum[i]) == tnum.end()) {
            tnum.push_back(vnum[i]);
        }
    }
    
    if(tnum.size() == 1) cout << tnum[0] << '\n';
    else {
        sort(tnum.begin(), tnum.end());
        cout << tnum[1] << '\n';
    }
    
    cout << (int)max - min;
}