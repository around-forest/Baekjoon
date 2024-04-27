#include <iostream>

int main(){
    int a,b,c,d;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);
    d = (b+c)/60;
    if(d == 0) printf("%d %d", a, b+c);
    else {
        if(a+d > 23) printf("%d %d", a+d-24, (b+c)-60*d);
        else printf("%d %d", a+d, (b+c)-60*d);
    }
}