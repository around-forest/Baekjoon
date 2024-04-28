#include <iostream>

int main(){
    int n, a[101], v, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &v);
    for(int i = 1; i <= n; i++)
        if(a[i] == v) sum++;
    printf("%d", sum);
    
}