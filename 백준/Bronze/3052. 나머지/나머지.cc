#include <iostream>

int main(){
    int n, a[11], b[42], count = 0;
    for(int i = 0; i <= 41; i++) b[i] = i;
    for(int i = 1; i <= 10; i++){
        scanf("%d", &n);
        a[i] = n%42;
        for(int l = 0; l <= 41; l++) if(b[l] == a[i]) b[l] = -1;
    }
    for(int i = 0; i <= 41; i++) if(b[i] == -1) count++;
    printf("%d", count);
}