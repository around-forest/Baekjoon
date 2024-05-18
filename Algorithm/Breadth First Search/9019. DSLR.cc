#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int T, A, B;
bool check[10001];

void bfs() {
    queue<pair<int, string>> q;
    q.push({A, ""});
    check[A] = true;
    
    while(!q.empty()) {
        int numb = q.front().first;
        string list = q.front().second;
        q.pop();
        
        if(numb == B) {
            cout << list << '\n';
            return;
        }
        
        int D = (numb * 2) % 10000;
        if(!check[D]) {
            check[D] = true;
            q.push({D, list + 'D'});
        }
        
        int S = numb - 1 < 0 ? 9999 : numb - 1;
        if(!check[S]) {
            check[S] = true;
            q.push({S, list + 'S'});
        }
        
        int L = (numb % 1000) * 10 + (numb / 1000);
        if(!check[L]) {
            check[L] = true;
            q.push({L, list + 'L'});
        }
        
        int R = (numb / 10) + (numb % 10) * 1000;
        if(!check[R]) {
            check[R] = true;
            q.push({R, list + 'R'});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    while(T--) {
        cin >> A >> B;
        
        memset(check, false, sizeof(check));
        
        bfs();
    }
}
