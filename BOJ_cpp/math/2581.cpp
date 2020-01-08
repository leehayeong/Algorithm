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
	int a, b;

	scanf("%d %d", &a, &b);

	int sum = 0;
	int min = b;
	for (int i = a; i <= b; i++) {
		if (isPrime(i)) {
			if (i < min) min = i;
			sum += i;
		}
	}

	if (sum == 0) printf("-1");
	else printf("%d %d", sum, min);
}