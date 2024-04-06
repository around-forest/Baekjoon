#include <iostream>
#include <cmath>
using namespace std;

int N, M;
bool check[31][15001];
int weight[31];

void dp(int i, int w) {
    if(i > N || check[i][w]) return;
    check[i][w] = true;
    
    dp(i + 1, w + weight[i]);
    dp(i + 1, abs(w - weight[i]));
    dp(i + 1, w);
    
    return;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> weight[i];
    }
    
    cin >> M;
    dp(0, 0);
    
    for(int i = 0; i < M; i++) {
        int marble;
        cin >> marble;
        
        if(marble > 15000) cout << "N ";
        else if(check[N][marble]) cout << "Y ";
        else cout << "N ";
    }
}