#include <iostream>
using namespace std;

int n, minCost;
int dist[100001], cost[100001];
long long totalCost = 0;

int main() {
    cin >> n;
    
    for(int i = 0; i < n-1; i++) {
        cin >> dist[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    
    minCost = cost[0];
    totalCost = cost[0] * dist[0];
    
    for(int i = 1; i < n-1; i++) {
        if(cost[i] < cost[i-1]) {
            minCost = cost[i];
            totalCost += minCost * dist[i];
        } else {
            totalCost += minCost * dist[i];
        }
    }
    
    cout << totalCost;
}
