#include <iostream>

int main(){
    int n, a[1000001], b, c;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    b = a[1];
    c = a[1];
    for(int i = 1; i <= n; i++){
        if(b < a[i]) b = a[i];
        if(c > a[i]) c = a[i];
    }
    printf("%d %d", c, b);
}