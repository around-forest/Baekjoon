#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Euclidean(int a, int b) {
    int r = a % b;
    if(r == 0)
        return b;
    else
        return Euclidean(b, r);
}

int main() {
    int n, tmp1, tmp2, gcd, result = 0;
    vector<int> distance;
    
    cin >> n;
    
    cin >> tmp1;
    distance.push_back(tmp1);
    
    // get distances btw trees
    for(int i = 0; i < n-1; i++) {
        cin >> tmp2;
        distance.push_back(tmp2-tmp1);
        tmp1 = tmp2;
    }
    
    // sort distances
    sort(distance.rbegin(), distance.rend());
    
    // get gcd using Euclidean
    gcd = distance[0];
    for(int i = 1; i < n-1; i++) {
        gcd = Euclidean(gcd, distance[i]);
    }
    
    // get the result
    for(int i = 0; i < n-1; i++) {
        result += (distance[i] / gcd) - 1;
    }
    
    cout << result;
}
