#include <iostream>
#include <string>

int main(){
    std::string a;
    int b = 1;
    
    getline(std::cin, a);
    for(int i = 0; i < a.length(); i++) if(a[i] == ' ') b++;
    if(a[0] == ' ') b--; if(a[a.length()-1] == ' ') b--;
    printf("%d", b);
}