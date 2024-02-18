#include <iostream>
using namespace std;

int N, M;
int *result;

/*
bool promising(int i) {
	int j = 0;
	
	while(j < i) {
		if(result[i] == result[j]) return false;
		j++;
	}
	return true; 
}  
*/

void backtracking(int node) {
	if(node == M) {
		for(int i = 0; i < M; i++) cout << result[i] << ' ';
		cout << '\n';
	} else {
		for(int i = 1; i <= N; i++) {
			result[node] = i;
			//if(promising(node)) 
			backtracking(node+1);
		}
	}
}

int main() {
    cin >> N >> M;
    result = new int[M];
    
    backtracking(0);
}