#include <iostream>
using namespace std;

long long N, B;
long long matrix[5][5], result[5][5], tmp[5][5];

void merge(long long x[5][5], long long y[5][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[i][j] += (x[i][k] * y[k][j]);
            }

            tmp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin >> N >> B;
    
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
        result[i][i] = 1;
    }
    
    while (B > 0) {
        if (B % 2) {
            merge(result, matrix);
        }
        merge(matrix, matrix);
        
        B /= 2;
    }
    
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}
