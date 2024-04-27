#include <iostream>

int main(){
    int a, b, x, n, sum = 0;
    scanf("%d", &x);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a, &b);
        sum += (a*b);
    }
    if(sum == x) printf("Yes");
    else printf("No");
}