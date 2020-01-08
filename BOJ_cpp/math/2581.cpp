#include <cstdio>
#include <iostream>

using namespace std;

// �����佺�׳��� ü�� �̿��ؼ��� Ǯ �� �ִ�.
// (�� Ǯ�̴� �ٸ� Ǯ��)

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