#include <iostream>
#include <string>
using namespace std;

int main(){
    string name[21];
    double score[21], a = 0, b = 0;
    string grade[21];
    
    for(int i = 0; i < 20; i++){
        cin >> name[i] >> score[i] >> grade[i];
    }
    for(int i = 0; i < 20; i++){
        if(grade[i].compare("P") == 0) continue;
        else if(grade[i].compare("A+") == 0){
            a += 4.5 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("A0") == 0){
            a += 4.0 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("B+") == 0){
            a += 3.5 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("B0") == 0){
            a += 3.0 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("C+") == 0){
            a += 2.5 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("C0") == 0){
            a += 2.0 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("D+") == 0){
            a += 1.5 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("D0") == 0){
            a += 1.0 * score[i];
            b += score[i];
        }
        else if(grade[i].compare("F") == 0){
            a += 0.0 * score[i];
            b += score[i];
        }
    }
    cout << a/b;
}