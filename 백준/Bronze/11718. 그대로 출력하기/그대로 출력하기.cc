#include <stdio.h>
#define LEN 101
int main(){
    char temp[LEN];
    while(fgets(temp, LEN, stdin)){
        printf("%s", temp);
    }
}