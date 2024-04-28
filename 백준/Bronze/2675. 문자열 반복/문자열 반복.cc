#include <iostream>
#include <cstring>

int main(){
    int t, r;
    char a[21];
    
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %s", &r, a);
        for(int j = 0; j < (int)strlen(a); j++) for(int l = 1; l <= r; l++) printf("%c", a[j]);
        printf("\n");
    }
    
}