#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<char, char>> graph[27];

void preorder(int node) {
    if(node + 'A' == '.') return;
    
    cout << char(node + 'A');
    preorder(graph[node][0].first - 'A');
    preorder(graph[node][0].second - 'A');
}

void inorder(int node) {
    if(node + 'A' == '.') return;
    
    inorder(graph[node][0].first - 'A');
    cout << char(node + 'A');
    inorder(graph[node][0].second - 'A');
}

void postorder(int node) {
    if(node + 'A' == '.') return;
    
    postorder(graph[node][0].first - 'A');
    postorder(graph[node][0].second - 'A');
    cout << char(node + 'A');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        char node, leftNode, rightNode;
        cin >> node >> leftNode >> rightNode;
        graph[node - 'A'].push_back(make_pair(leftNode, rightNode));
    }
    
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}