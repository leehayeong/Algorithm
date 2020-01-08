#include <cstdio>
#include <iostream>

using namespace std;

// 에라토스테네의 체를 이용해서도 풀 수 있다.
// (이 풀이는 다른 풀이)

bool isPrime(int n) {
	if (n < 2) return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int t, n;
	int cnt = 0;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		if (isPrime(n)) cnt++;
	}

	printf("%d", cnt);
}