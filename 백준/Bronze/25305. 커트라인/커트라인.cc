#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, k, tmp;
    cin >> n >> k;
    int s[n+1];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(s[i] < s[j]){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
    cout << s[k-1];
}