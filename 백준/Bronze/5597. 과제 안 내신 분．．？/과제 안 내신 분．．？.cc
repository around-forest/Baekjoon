#include <iostream>

int main(){
    int n, a[31]={0,};
    for(int i = 1; i <= 28; i++){
        scanf("%d", &n);
        a[n] = 1;
    }
    for(int i = 1; i <= 30; i++) if(a[i] == 0) printf("%d\n", i);
}