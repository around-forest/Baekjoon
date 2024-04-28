#include <iostream>

int main(){
    int n, m, i, j, a[101];
    scanf("%d %d", &n, &m);
    for(int l = 1; l <= n; l++) a[l] = l;
    for(int l = 1; l <= m; l++){
        scanf("%d %d", &i, &j);
        int b = i, c = j;
        for(int p = 1; p <= (j-i+1)/2; p++){
            int tmp = a[b];
            a[b++] = a[c];
            a[c--] = tmp;
        }
    }
    for(int l = 1; l <= n; l++) printf("%d ", a[l]);
}