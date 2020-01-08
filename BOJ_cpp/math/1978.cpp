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
	int t, n;
	int cnt = 0;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		if (isPrime(n)) cnt++;
	}

	printf("%d", cnt);
}