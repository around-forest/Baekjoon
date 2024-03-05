// DP -> Optimal Substructure / Memoization / Top-down / Bottom-up
// n = 1일때 9개의 계단수가 존재하고 n = 2일때 8이 증가한다. 단순히 +8이라 생각하는 것
// 보다는 1부터 8까지는 *2, 9는 +1의 개념으로 접근해보자.
// 1번 배열에 9를 넣고 인덱스 i가 n까지 증가함에 따라 i의 값 *2 -1로 접근.
// n = 3까지 트리 구조로 표현해보고 구현.
// array[1] = 9, 1~9
// array[2] = 9 * 2 - 1, 1->0,2/ 2->1,3/ 3->2,4 ... 8->7,9/ 9->8
// array[3] = (9*2-1)*2-2, 1->0->1/ 1->2->1/ 1->2->3/ 2->1->0/ 2->1->2/
// 2->3->2/ 2->3->4/ 3->2->1/ 3->2->3/ 3->4->3/ 3->4->5/ ... 8->7->6/
// 8->7->8/ 8->9->8/ 9->8->7/ 9->8->9 (1/ 8 3개, 2~7 4개씩, 9는 두개 = 32)

#include <iostream>
using namespace std;

int n, count = 0;
int tmp[101][10] = {0,};

void DP(int x) {
    for(int i = 0; i <= 9; i++) {
        if(i == 0) tmp[x][1] += tmp[x-1][i];
        else if(i == 9) tmp[x][8] += tmp[x-1][i];
        else {
            tmp[x][i-1] += tmp[x-1][i];
            tmp[x][i+1] += tmp[x-1][i];
        }
        
        tmp[x][i] %= 1000000000;
    }
}

int main() {
    cin >> n;
    
    for(int i = 1; i <= 9; i++) {
        tmp[1][i] = 1;
    }
    
    for(int i = 2; i <= n; i++) {
        DP(i);
    }
    
    for(int i = 0; i <= 9; i++) {
        count += (tmp[n][i] % 1000000000);
    }
    
    cout << count;
    
}
