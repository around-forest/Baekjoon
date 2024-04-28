#include <iostream>

int main(){
    float n, a[1001], m, sum = 0;
    scanf("%f", &n);
    for(int i = 1; i <= n; i++) scanf("%f", &a[i]);
    m = a[1];
    for(int i = 1; i <= n; i++) if(m < a[i]) m = a[i];
    for(int i = 1; i <= n; i++) a[i] = a[i]/m*100;
    for(int i = 1; i <= n; i++) sum += a[i];
    printf("%.2f", sum/n);
}