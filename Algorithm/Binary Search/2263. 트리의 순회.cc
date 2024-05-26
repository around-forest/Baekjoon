#include <iostream>
using namespace std;

int n;
int inorder[100002];
int postorder[100002];
int inorderIndex[100002];

void binarySearch(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart > inEnd || postStart > postEnd) return;
    
    int rootIndex = inorderIndex[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    
    cout << inorder[rootIndex] << ' ';
    
    binarySearch(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    binarySearch(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> inorder[i];
        inorderIndex[inorder[i]] = i;
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }
    
    binarySearch(1, n, 1, n);
}
