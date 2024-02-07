#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    vector<int> circle;
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
        circle.push_back(i);
    }
    
    cout << '<';
    
    for(int i = k-1; circle.size() != 1; i+=(k-1)) {
        while(i >= circle.size()) {
            i -= circle.size();
        }
        cout << circle[i] << ", ";
        circle.erase(circle.begin() + i);
    }
    
    cout << circle[0] << '>';
}