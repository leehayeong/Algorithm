#include <cstdio>
#include <iostream>

using namespace std;

// 에라토스테네의 체

int main() {
	int n, cnt;
	bool arr[123456 * 2 + 1];
	
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;

		fill_n(arr, 2 * n + 1, true);
		arr[1] = false;
		for (int i = 2; i * i <= 2 * n; i++) {
			if (arr[i]) {
				int mul = 2;
				for (int j = i * mul; j <= 2 * n; j = i * mul) {
					arr[j] = false;
					mul++;
				}
			}
		}

		cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i]) cnt++;
		}

		printf("%d\n", cnt);
	}
}