#include <iostream>

int main(){
    int a;
    scanf("%d", &a);
    for(int i = 1; i <= a; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        printf("Case #%d: %d + %d = %d\n", i, x, y, x+y);
    }
}