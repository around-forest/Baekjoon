#include <iostream>
#include <queue>
using namespace std;

int main() {
    bool turn = true;
    int n, numb = 1;
    queue<int> que;
    
    cin >> n;
    
    while(n--) {
        que.push(numb++);
    }
    
    while(que.size() != 1) {
        if(turn) {
            que.pop();
            turn = false;
        } else {
            que.push(que.front());
            que.pop();
            turn = true;
        }
    }
    
    cout << que.front();
}