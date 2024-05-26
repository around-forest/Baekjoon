#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> tree;

void preorder(int startIndex, int endIndex) {
    if(endIndex <= startIndex) return;
    if(startIndex == endIndex - 1) {
        cout << tree[startIndex] << '\n';
        return;
    }
    
    int index = startIndex + 1;
    while(index < endIndex) {
        if(tree[startIndex] < tree[index]) break;
        index++;
    }
    
    preorder(startIndex + 1, index);
    preorder(index, endIndex);
    
    cout << tree[startIndex] << '\n';
}

int main() {
    while(cin >> n) {
        tree.push_back(n);
    }
    
    preorder(0, tree.size());
}
