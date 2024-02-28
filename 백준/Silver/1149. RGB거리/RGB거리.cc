#include <iostream>
#include <algorithm>
using namespace std;

int color[1001][3] = {0,};
int cost[3];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        
        color[i][0] = min(color[i-1][1], color[i-1][2]) + cost[0];
        color[i][1] = min(color[i-1][0], color[i-1][2]) + cost[1];
        color[i][2] = min(color[i-1][0], color[i-1][1]) + cost[2];
    }
    
    cout << min(color[n-1][0], min(color[n-1][1], color[n-1][2]));
}