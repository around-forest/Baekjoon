#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> series, result;

int binarySearch(int k) {
    int low = 0, high = result.size() - 1, mid;
    
    while(low < high) {
        mid = (high + low) / 2;
        
        if(result[mid] >= k) high = mid;
        else low = mid + 1;
    }
    
    return high;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        series.push_back(tmp);
    }
    result.push_back(series.front());
    
    for(int i = 1; i < N; i++) {
        int tmp, index;
          
        if(result.back() < series[i]) {
            result.push_back(series[i]);
        } else {
            result[binarySearch(series[i])] = series[i];
        }
    }
    
    cout << result.size();
}
