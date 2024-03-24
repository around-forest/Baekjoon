#include <iostream>
#include <algorithm>
using namespace std;

long long K, N, L[10001], result, leftV = 1, rightV = 0, midV;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> K >> N;
    
    for(int i = 0; i < K; i++) {
        cin >> L[i];
        if(L[i] > rightV) rightV = L[i];
    }
    
    while(leftV <= rightV) {
        int tmp = 0;
        midV = (leftV + rightV) / 2;
        
        for(int i = 0; i < K; i++) {
            tmp += (L[i] / midV);
        }
        
        if(tmp >= N) {
            leftV = midV + 1;
            result = max(result, midV);
        } else {
            rightV = midV - 1;
        }
    }
    
    cout << result;
}