#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long N, leftV, rightV, minV = 2000000001;
long long arr[100001];

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    int left = 0, right = N - 1;
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(abs(sum) < minV) {
            minV = abs(sum);
            leftV = arr[left];
            rightV = arr[right];
        }
        
        if(sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << leftV << ' ' << rightV << '\n';
}