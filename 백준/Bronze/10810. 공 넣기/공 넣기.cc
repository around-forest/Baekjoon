#include <iostream>

int main(){
    int n,m, a[101] = {0,}, i, j ,k;
    scanf("%d %d", &n, &m);
    for(int l = 1; l <= m; l++){
        scanf("%d %d %d", &i, &j, &k);
        for(i; i <= j; i++) a[i] = k;
    }
    for(int l = 1; l <= n; l++) printf("%d ", a[l]);
}