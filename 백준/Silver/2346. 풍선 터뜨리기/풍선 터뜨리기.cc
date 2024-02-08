#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp, index;
    vector<int> circle, numb;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        circle.push_back(i);
        numb.push_back(tmp);
    }
    
    index = circle.size();
    
    for(int i = 0; index != 1;) {
        while(i >= index) {
            i = (i%index);
        }
        
        cout << circle[i] + 1 << ' ';
        tmp = numb[i];
        circle.erase(circle.begin() + i);
        numb.erase(numb.begin() + i);
        
        index = circle.size();
        
        if(tmp > 0) i += (tmp-1);
        else i += tmp;
        
        while(i < 0) {
            i = (i%index) + index;
        }
    }
    cout << circle[0] + 1;
}