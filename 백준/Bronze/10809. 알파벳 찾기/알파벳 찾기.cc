#include <iostream>
#include <cstring>

int main(){
    char a[101];
    
    scanf("%s", a);
    for(int i = 'a'; i < 'a'+26; i++){
        int b = -1;
        for(int j = 0; j < strlen(a); j++){
            if((int)a[j] == i){
                b = j;
                break;
            }
        }
        printf("%d ", b);
    }
}