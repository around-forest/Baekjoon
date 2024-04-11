#include <iostream>
#include <stack>
using namespace std;

int N, numb;
int count[1000001] = {0, };
int series[1000001];
stack<int> tmp;

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> series[i];
        count[series[i]]++;
    }
    
    for(int i = 0; i < N; i++) {
        numb = series[i];
        
        while(1) {
            if(tmp.empty()) {
                tmp.push(i);
                break;
            } else {
                if(count[series[tmp.top()]] < count[numb]) {
                    series[tmp.top()] = numb;
                    tmp.pop();
                } else {
                    tmp.push(i);
                    break;
                }
            }
        }
    }
    
    while(!tmp.empty()) {
        series[tmp.top()] = -1;
        tmp.pop();
    }
    
    for(int i = 0; i < N; i++) cout << series[i] << ' ';
}