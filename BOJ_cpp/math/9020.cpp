#include <cstdio>
#include <iostream>

using namespace std;

// 골드바흐 수 = 2보다 큰 모든 짝수는 소수의 합으로 나타낼 수 있다.
// 골드바흐 파티션 = 짝수를 두 소수의 합으로 나타내는 표현. 합이 되는 수
// n의 골드바흐 파티션을 출력 (두 차이가 가장 적은 것으로)

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