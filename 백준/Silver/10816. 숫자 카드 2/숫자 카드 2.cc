#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    map<int, int> number;
    int n, m, tmp1, tmp2;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> tmp1;
        if(number.find(tmp1) != number.end()) {
            number[tmp1] += 1;
        } else {
            number.insert(make_pair(tmp1, 1));
        }
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> tmp1;
        cout << number[tmp1] << ' ';
    }
}