#include <iostream>
#include <cstring>

int main(){
    char a[1001];
    int i;
    
    scanf("%d", &i);
    for(int j = 1; j <= i; j++){
        scanf("%s", a);
        printf("%c%c\n", a[0], a[(int)strlen(a)-1]);
    }
}