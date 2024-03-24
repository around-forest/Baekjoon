#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, trees[1000001];
long long leftV = 1, rightV = 0, mid, result = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> trees[i];
        if(trees[i] > rightV) rightV = trees[i];
    }
    
    while(leftV <= rightV) {
        long long tmp = 0;
        mid = (leftV + rightV) / 2;
        
        for(int i = 0; i < N; i++) {
            if(trees[i] > mid) tmp += (trees[i] - mid);
        }
        
        if(tmp >= M) {
            leftV = mid + 1;
            result = max(result, mid);
        } else {
            rightV = mid - 1;
        }
    }
    cout << result;
}
