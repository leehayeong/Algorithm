#include <cstdio>
#include <iostream>

using namespace std;

// 에라토스테네의 체

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	bool arr[1000001];
	fill_n(arr, n+1, true);
	arr[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (arr[i]) {
			// 배수도 모두 제거
			int mul = 2;
			for (int j = i * mul; j <= n; j = i * mul) {
				arr[j] = false;
				mul++;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (arr[i]) printf("%d\n", i);
	}
}