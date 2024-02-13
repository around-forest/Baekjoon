#include <iostream>
using namespace std;

int n, k, count;
int a[500001];
int *tmp;

void merge(int p, int q, int r) {
    int i = p, j = q+1, t = 1;
    
    while(i <= q && j <= r) {
        if(a[i] <= a[j]) {
            tmp[t++] = a[i++];
        } else {
            tmp[t++] = a[j++];
        }
    }
    while(i <= q) {
        tmp[t++] = a[i++];
    }
    while(j <= r) {
        tmp[t++] = a[j++];
    }
    i = p;
    t = 1;
    while(i <= r) {
        if(count == 1) cout << tmp[t];
        a[i++] = tmp[t++];
        count--;
    }
}

void merge_sort(int p, int r) {
    int q;
    
    if(p < r) {
        q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q+1, r);
        merge(p, q, r);
    }
}

int main() {
    cin >> n >> k;
    
    tmp = (int *)malloc(sizeof(int) * n);
    count = k;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    merge_sort(0, n-1);
    
    if(count > 0) cout << -1;
}