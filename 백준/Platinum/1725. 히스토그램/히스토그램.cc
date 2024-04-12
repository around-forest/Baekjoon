#include <iostream>
#include <stack>
using namespace std;

int n;
long long maxArea = 0;
long long histogram[100001];
stack<int> tmp;

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> histogram[i];
    }
    
    for(int i = 0; i < n; i++) {
        while(!tmp.empty() && histogram[i] < histogram[tmp.top()]) {
            long long top = histogram[tmp.top()];
            int dist = i;
            tmp.pop();
            
            if(!tmp.empty()) dist = i - tmp.top() - 1;
            long long tmpArea = top * dist;
            
            if(tmpArea > maxArea) maxArea = tmpArea;
        }
        tmp.push(i);
    }
    
    while(!tmp.empty()) {
        long long top = histogram[tmp.top()];
        int dist = n;
        tmp.pop();
        
        if(!tmp.empty()) dist = n - tmp.top() - 1;
        long long tmpArea = top * dist;
        
        if(tmpArea > maxArea) maxArea = tmpArea;
    }
    
    cout << maxArea << '\n';
    
}