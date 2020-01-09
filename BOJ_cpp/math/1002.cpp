#include <cstdio>
#include <algorithm>

using namespace std;

// 터렛
// 조규현 x1, x2, r1, 백승환 x2, y2, r2
// r1이 조규현으로부터 류재명이 있을 수 있는 거리. 즉 원의 반지름
// r2도 마찬가지로 백승환의 원의 반지름
// 조규현의 원과 백승환의 원의 교점의 수 = 류재명이 있을 수 있는 좌표의 수

int main() { 
	int t, x1, y1, r1, x2, y2, r2, result;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		result = 0;

		// 1. 두 중점사이의 거리를 기준으로 교점의 수를 구한다. (제곱으로 비교)
		int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		int rs = (r1 + r2) * (r1 + r2);
		int rm = (r1 - r2) * (r1 - r2);

		// 2. 무한히 많다. (두 원이 일치한다.)
		if (dist == 0 && r1 == r2) {
			result = -1;
		}

		// 3. 만나지 않는다.
		else if (dist == 0 || dist > rs) {
			result = 0;
		}

		// 4. 한 점에서 만난다.
		else if (dist == rs || dist == rm) {
			result = 1;
		}

		// 5. 두 점에서 만난다.
		else if (rm < dist && dist < rs) {
			result = 2;
		}

		printf("%d\n", result);
	}
}