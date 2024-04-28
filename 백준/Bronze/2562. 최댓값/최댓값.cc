#include <iostream>

int main(){
    int a[10], b, c = 1;
    for(int i = 1; i <= 9; i++) scanf("%d", &a[i]);
    b = a[1];
    for(int i = 1; i <= 9; i++)
        if(b < a[i]){
            b = a[i];
            c = i;
        }
    printf("%d\n%d", b, c);
}