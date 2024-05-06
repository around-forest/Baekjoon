#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	set<string> name;
	string a, b;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(b == "enter") name.insert(a);
		else if(b == "leave") name.erase(a);
	}
	
	for(auto r = name.rbegin(); r != name.rend(); ++r){
		cout << *r << "\n";
	}
	
	return 0;
}