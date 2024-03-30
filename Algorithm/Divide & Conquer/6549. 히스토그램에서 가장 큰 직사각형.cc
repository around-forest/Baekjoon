#include <iostream>
#include <stack>
using namespace std;

long long histogram[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    
    while(1) {
        stack<int> stack;
        int n;
        long long maxArea = 0;
        
        cin >> n;
        if(n == 0) break;
        
        for(int i = 0; i < n; i++) {
            cin >> histogram[i];
        }
        
        for(int i = 0; i < n; i++) {
            while(!stack.empty() && histogram[i] < histogram[stack.top()]) {
                long long top = histogram[stack.top()];
                int dist = i;
                stack.pop();
                
                if(!stack.empty()) dist = i - stack.top() - 1;
                long long tmpArea = top * dist;
                
                if(tmpArea > maxArea) maxArea = tmpArea;
            }
            stack.push(i);
        }
        
        while(!stack.empty()) {
            long long top = histogram[stack.top()];
            int dist = n;
            stack.pop();
            
            if(!stack.empty()) dist = n - stack.top() - 1;
            long long tmpArea = top * dist;
            
            if(tmpArea > maxArea) maxArea = tmpArea;
        }
        
        cout << maxArea << '\n';
    }
}
