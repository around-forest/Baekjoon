#include <iostream>
#include <algorithm>
using namespace std;

int N, S, minLength = 1e9;
int arr[100001] = {0,};

int main() {
    cin >> N >> S;
    
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    int start = 0, end = 1, sum = arr[start] + arr[end];
    
    while(start <= end) {
        if(sum >= S) {
            minLength = min(minLength, end - start);
            sum -= arr[++start];
        } else {
            sum += arr[++end];
        }
        
        if(end > N) break;
    }
    
    if(minLength == 1e9) cout << 0;
    else cout << minLength;
}