#include <iostream>
#include <stack>
using namespace std;

int N, numb;
int series[1000001];
stack<int> oaken;

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> numb;
        series[i] = numb;
        
        while(1) {
            if(oaken.empty()) {
                oaken.push(i);
                break;
            } else {
                if(series[oaken.top()] < numb) {
                    series[oaken.top()] = numb;
                    oaken.pop();
                } else {
                    oaken.push(i);
                    break;
                }
            }
        }
    }
    
    while(!oaken.empty()) {
        series[oaken.top()] = -1;
        oaken.pop();
    }
    
    for(int i = 0; i < N; i++) cout << series[i] << ' ';
}