#include <iostream>
using namespace std;

int N, M, K;
int A[101][101], B[101][101], result[101][101];

int main() {
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    
    cin >> M >> K;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            for(int k = 0; k < M; k++) {
                result[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}