#include <cstdio>
#include <algorithm>

using namespace std;

/*
��� A�� N�� ��¥ ������,
1. N�� A�� ���
2. A != 1 && A != N
��� ����� �־��� ��, N��?
*/

int n, a[50];

int main() {
	scanf("%d", &n);
	int mul = 1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// ���� ���� ����� ���� ū ����� ���ϸ� ������ ���� ���´�.
	sort(a, a + n);
	mul = a[0] * a[n - 1];

	printf("%d", mul);
}