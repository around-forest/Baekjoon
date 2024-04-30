#include <iostream>
#include <string>

int main(){
    std::string b;
    std::cin >> b;

    for(int i = 0; i < b.length() / 2; i++)
        if(b[i] != b[b.length() - 1 - i]){
            std::cout << 0;
            return 0;
        }
        std::cout << 1;
        return 0;

}