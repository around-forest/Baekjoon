#include <iostream>
using namespace std;

int main(){   
    int a, b, c;
    cin >> a >> b>> c;
    if(a + b+ c != 180) cout << "Error";
    else if(a == b && b == c) cout << "Equilateral";
    else if(a == b && b != c) cout << "Isosceles";
    else if(a == c && b != c) cout << "Isosceles";
    else if(c == b && a != c) cout << "Isosceles";
    else if(a != b && b != c && a != c) cout << "Scalene";
}