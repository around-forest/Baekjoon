#include <iostream>
using namespace std;

int T;

int main() {
    cin >> T;
    
    while(T--) {
        int node, edge, tmp1, tmp2;
        
        cin >> node >> edge;
        
        while(edge--) {
            cin >> tmp1 >> tmp2;
        }
        
        cout << node - 1 << '\n';
    }
}