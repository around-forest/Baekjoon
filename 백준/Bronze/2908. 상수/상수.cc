#include <iostream>

int main(){
    int a, b, a1, a2, a3, b1, b2, b3;
    
    scanf("%d %d", &a, &b);
    a1 = a / 100;
    a2 = (a%100)/10;
    a3 = (a%100)%10;
    b1 = b/100;
    b2 = (b%100)/10;
    b3 = (b%100)%10;
    
    if(a3 > b3) printf("%d%d%d", a3,a2,a1);
    else if(a3 < b3) printf("%d%d%d", b3,b2,b1);
    else if(a3 == b3){
        if(a2 > b2) printf("%d%d%d", a3,a2,a1);
        else if(b2 > a2) printf("%d%d%d", b3,b2,b1);
        else if(a2 == b2){
            if(a1 > b1) printf("%d%d%d", a3,a2,a1);
            else if(b1 > a1) printf("%d%d%d", b3,b2,b1);
        }
    }
}