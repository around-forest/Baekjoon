#include <iostream>
using namespace std;
int main(){
    int n, a, b;
    std::cin.tie(NULL);
    ios::sync_with_stdio(false);
    std::cin >> n;
    while(n--){
        std::cin >> a >> b;
        std::cout << a+b << "\n";
    }
}