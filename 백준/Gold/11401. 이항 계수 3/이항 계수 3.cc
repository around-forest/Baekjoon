/* 
큰 수의 곱들의 나머지는 분할 정복을 이용하여 매번 계산시에 나머지를 구한 후
나머지로만 남은 연산을 실시하여도 같은 결과가 나온다는 사실.
이항계수인 n! / (n-k)!k! % p는 페르마의 소정리를 통해
n! % p * (n-k)!k! % p -> (n! % p) * (((n-k)!k!)^p-2 % p)로 표현할 수 있다.
팩토리얼은 팩토리얼 함수를 통해 각각 구하고, ^p-2의 곱셈은 1629번의 곱셈 문제와 같은
분할정복을 이용한 곱셈으로 구한다.
*/
#include <iostream>
using namespace std;

long long N, K, tmp, denominator, numerator, P = 1000000007;

long long factorial(int n) {
    long long result = 1;
    for(int i = 2; i <= n; i++) result = (result * i) % P;
    
    return result;
}

long long merge(int n, int p) {
    if(p == 0) return 1;
    if(p == 1) return n;
    
    tmp = merge(n, p / 2) % P;
    
    if(p % 2 == 0) return tmp * tmp % P;
    return tmp * tmp % P * n % P;
}

int main() {
    cin >> N >> K;
    
    numerator = factorial(N) % P;
    denominator = merge(factorial(K) * factorial(N-K) % P, P - 2);
    
    cout << numerator * denominator % P;
}