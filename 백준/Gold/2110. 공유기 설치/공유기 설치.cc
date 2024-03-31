#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, maxDist, leftDist = 0, rightDist, midDist, resultDist;
vector<int> house;

int main() {
    cin >> N >> C;
    
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        house.push_back(tmp);
    }
    
    sort(house.begin(), house.end());
    
    leftDist = house[0] - house[0];
    rightDist = house[N-1] - house[0];
    
    while(leftDist <= rightDist) {
        int count = 1;
        midDist = (leftDist + rightDist) / 2;
        
        int start = house[0];
        
        for(int i = 1; i < N; i++) {
            int end = house[i];
            
            if(end - start >= midDist) {
                count++;
                start = end;
            }
        }
        
        if(count >= C) {
            resultDist = midDist;
            leftDist = midDist + 1;
        } else {
            rightDist = midDist - 1;
        }  
    }
    
    cout << resultDist;
}