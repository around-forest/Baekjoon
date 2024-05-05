#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<pair<int, string> > v;

int main(){
	int n, l;
    string w;
	cin >> n;
    
	for(int i = 0; i < n; i++){
		cin >> w;
        l = w.length();
		v.push_back({l, w});
	}
    
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(v[i].second == v[j].second) v[j].second = "0";
        }
    }
    
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
        if(v[i].second != "0") cout << v[i].second << '\n';
    }
}