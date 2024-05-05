#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, string> > v;

bool compare(const pair<int, string> &a , const pair<int, string> &b){
    return a.first < b.first;
}

int main(){
	int n, l;
    string w;
	cin >> n;
    int v_index[n+1];
     
        
	for(int i = 0; i < n; i++){
		cin >> l >> w;
		v.push_back({l, w});
	}
    
	stable_sort(v.begin(), v.end(), compare);
    
	for(int i = 0; i < n; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
}