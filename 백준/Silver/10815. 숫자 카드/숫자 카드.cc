#include <iostream>
using namespace std;

int a[20000001] = {0};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n, m, tmp;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		a[tmp + 10000000] = 1;
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> tmp;
		cout << a[tmp + 10000000] << " ";
	}
}