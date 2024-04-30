#include <iostream>
#include <string>
using namespace std;

int main(){
    int alphabet[26] = {0,};
    string str;
    cin >> str;
    
    for(int i = 0; i< str.length(); i++){
        if(str[i] < 97) alphabet[str[i]-65]++;
        else alphabet[str[i]-97]++;
    }
        
    int max = alphabet[0], max_index = 0, nmax = 0;
    for(int i = 0; i < 26; i++)
        if(alphabet[i] > max){
            max = alphabet[i];
            max_index = i;
        }
            
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == max)
            nmax++;
    }
            
    if(nmax > 1) cout << "?";
    else cout <<  (char)(max_index + 65);
}