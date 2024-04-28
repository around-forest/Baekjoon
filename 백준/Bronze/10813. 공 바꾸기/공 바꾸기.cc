#include <iostream>

int main(){
    int n,m, a[101] = {0,}, i, j;
    scanf("%d %d", &n, &m);
    for(int l = 1; l <= n; l++) a[l] = l;
    for(int l = 1; l <= m; l++){
        scanf("%d %d", &i, &j);
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    for(int l = 1; l <= n; l++) printf("%d ", a[l]);
}