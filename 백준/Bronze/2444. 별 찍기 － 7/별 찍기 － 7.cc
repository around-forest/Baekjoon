#include <iostream>

int main(){
    int n, a, b, c;
    scanf("%d", &n);
    a = n-1;
    b = 1;
    c = 0;
    
    for(int i= 0; i < n; i++){
        for(int j = 0; j < a; j++) printf(" ");
        for(int j = 0; j < b; j++) printf("*");
        for(int j = 0; j < c; j++) printf("*");
        a--;
        b++;
        c++;
        printf("\n");
    }
    a += 2;
    b -= 2;
    c -= 2;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < a; j++) printf(" ");
        for(int j = 0; j < b; j++) printf("*");
        for(int j = 0; j < c; j++) printf("*");
        a++;
        b--;
        c--;
        printf("\n");
    }
}