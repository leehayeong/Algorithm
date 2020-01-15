#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
동전 n종류, 금액 k
금액을 만드는 동전개수의 최솟값
*/

int n, num[10], cnt;
long long k;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int i = n - 1;
	while (true) {
		// 사용 가능한 최대 화폐 단위 찾기
		// 4200 에서는 1000
		while (k / num[i] <= 0) i--;

		// num[i] = 1000
		// cnt = 4;
		// 사용 화폐 개수 더하기
		cnt += k / num[i];

		// k = 4200 - 4 * 1000 = 200
		// 남은 금액 계산
		k = k - (k / num[i]) * num[i];

		if (k == 0) break;
	}

	cout << cnt;
}