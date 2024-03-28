#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001

int N, result[MAX];
bool check[MAX];
vector<int> tree[MAX];

void dfs(int node) {
    check[node] = true;
    
    for(int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        if(!check[next]) {
            result[next] = node;
            dfs(next);
        }
    }
}

int main() { 
    cin >> N;
    
    for(int i = 0; i < N-1; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        
        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }
    
    dfs(1);
    
    for(int i = 2; i <= N; i++) cout << result[i] << '\n';
}