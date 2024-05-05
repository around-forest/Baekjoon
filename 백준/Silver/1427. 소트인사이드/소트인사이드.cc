#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string n;
    char tmp;
    cin >> n;
    for(int i = 0; i < n.length() - 1; i++){
        for(int j = i+1; j < n.length(); j++){
            if(n[i] < n[j]){
                tmp = n[i];
                n[i] = n[j];
                n[j] = tmp;
            }
        }
    }
    cout << n;
}