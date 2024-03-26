#include <iostream>
#include <queue>
using namespace std;

int N, tmp;
priority_queue<int, vector<int>, greater<int>> heap;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    while(N--) {
        cin >> tmp;
        
        if(tmp == 0) {
            if(heap.empty()) cout << 0 << '\n';
            else {
                cout << heap.top() << '\n';
                heap.pop();
            }
        } else {
            heap.push(tmp);
        }
    }
}