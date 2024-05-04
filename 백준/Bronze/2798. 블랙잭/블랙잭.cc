#include <iostream>
using namespace std;

int main(){
    int n, m, max = 0;
    cin >> n >> m;
    
    int num[n+1];
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(num[i] + num[j] + num[k] <= m && (num[i] + num[j] + num[k]) >= max) max = num[i] + num[j] + num[k];
            }
        }
    }
    cout << max;
}