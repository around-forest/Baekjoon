#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> v, tmp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, l;
	cin >> n;
    
	for(int i = 0; i < n; i++){
		cin >> l;
		v.push_back(l);
        tmp.push_back(l);
	}
    
	sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
	for(int i = 0; i < n; i++){
        cout << lower_bound(v.begin(), v.end(), tmp[i]) - v.begin() << " ";    
    }
}