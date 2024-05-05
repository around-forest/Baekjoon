#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, tmp, cnt[10001] = {0};
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        cnt[tmp]++;
    }
    
    for(int i = 1; i < 10001; i++){
        for(int j= 0; j < cnt[i]; j++){
            cout << i << '\n';
        }
    }
}