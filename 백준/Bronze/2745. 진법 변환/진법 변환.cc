#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    string N;
    int B, A, sum = 0, j = 0;
    
    cin >> N >> B;
    A = N.length();
    
    for(int i = A-1; i >= 0; i--, j++){
        if(N[i] == '0') sum += (0*pow(B, j));
        else if(N[i] == '1') sum += (1*pow(B, j));
        else if(N[i] == '2') sum += (2*pow(B, j));
        else if(N[i] == '3') sum += (3*pow(B, j));
        else if(N[i] == '4') sum += (4*pow(B, j));
        else if(N[i] == '5') sum += (5*pow(B, j));
        else if(N[i] == '6') sum += (6*pow(B, j));
        else if(N[i] == '7') sum += (7*pow(B, j));
        else if(N[i] == '8') sum += (8*pow(B, j));
        else if(N[i] == '9') sum += (9*pow(B, j));
        else if(N[i] == 'A') sum += (10*pow(B, j));
        else if(N[i] == 'B') sum += (11*pow(B, j));
        else if(N[i] == 'C') sum += (12*pow(B, j));
        else if(N[i] == 'D') sum += (13*pow(B, j));
        else if(N[i] == 'E') sum += (14*pow(B, j));
        else if(N[i] == 'F') sum += (15*pow(B, j));
        else if(N[i] == 'G') sum += (16*pow(B, j));
        else if(N[i] == 'H') sum += (17*pow(B, j));
        else if(N[i] == 'I') sum += (18*pow(B, j));
        else if(N[i] == 'J') sum += (19*pow(B, j));
        else if(N[i] == 'K') sum += (20*pow(B, j));
        else if(N[i] == 'L') sum += (21*pow(B, j));
        else if(N[i] == 'M') sum += (22*pow(B, j));
        else if(N[i] == 'N') sum += (23*pow(B, j));
        else if(N[i] == 'O') sum += (24*pow(B, j));
        else if(N[i] == 'P') sum += (25*pow(B, j));
        else if(N[i] == 'Q') sum += (26*pow(B, j));
        else if(N[i] == 'R') sum += (27*pow(B, j));
        else if(N[i] == 'S') sum += (28*pow(B, j));
        else if(N[i] == 'T') sum += (29*pow(B, j));
        else if(N[i] == 'U') sum += (30*pow(B, j));
        else if(N[i] == 'V') sum += (31*pow(B, j));
        else if(N[i] == 'W') sum += (32*pow(B, j));
        else if(N[i] == 'X') sum += (33*pow(B, j));
        else if(N[i] == 'Y') sum += (34*pow(B, j));
        else if(N[i] == 'Z') sum += (35*pow(B, j));
    }
    
    cout << sum;
}