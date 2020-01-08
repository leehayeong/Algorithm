#include <cstdio>
#include <iostream>

using namespace std;

// ������ �� = 2���� ū ��� ¦���� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
// ������ ��Ƽ�� = ¦���� �� �Ҽ��� ������ ��Ÿ���� ǥ��. ���� �Ǵ� ��
// n�� ������ ��Ƽ���� ��� (�� ���̰� ���� ���� ������)

int main() {
	int t, n, a, b;
	bool arr[10001];
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 0) break;

		fill_n(arr, n + 1, true);
		arr[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (arr[i]) {
				int mul = 2;
				for (int j = i * mul; j <= n; j = i * mul) {
					arr[j] = false;
					mul++;
				}
			}
		}

		for (int i = n / 2; i >= 1; i--) {
			if (arr[i] && arr[n - i]) {
				a = i;
				b = n - i;
				break;
			}
		}

		printf("%d %d\n", a, b);
	}
}