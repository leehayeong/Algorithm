#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
조합 0의 개수
뒷자리부터 0이 아닌 수가 나올때까지 0의 개수
nCm = n! / m! (n-m)!

0이 나오기 위해서는 5*2 가 반드시 포함되어야 한다.
즉, 5*2를 소인수로 포함하며, 이 쌍의 개수가 정답이다.

입력 수가 매우 크기 때문에 소인수를 다 찾는것은 비효율적이다.
n의 2와 5의 개수에서
m의 2와 5의 개수, (n-m)의 2와 5의 개수를 빼는 방법으로 해결한다. (나눠지므로)
*/

long long n, m;
int two, five;	

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	// n의 2와 5의 개수 (매우 큰 수이므로 배수로 나누어 확인한다.)
	for (long long i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		five += n / i;
	}

	// m의 2와 5의 개수 빼기
	for (long long i = 2; i <= m; i *= 2) {
		two -= m / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		five -= m / i;
	}

	// n-m의 2와 5의 개수 빼기
	for (long long i = 2; i <= n - m; i *= 2) {
		two -= (n - m) / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		five -= (n - m) / i;
	}

	cout << min(two, five);
}