#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n, m, count = 0;
	
	cin >> n >> m;
	vector <string> set(n);
	string word;
	
	for(int i = 0; i < n; i++){
		cin >> set[i];
	}
	
	sort(set.begin(), set.end());
	
	for(int i = 0; i < m; i++){
		cin >> word;
		if(binary_search(set.begin(), set.end(), word)) count++;
	}
	cout << count;
}