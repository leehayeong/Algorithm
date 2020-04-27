#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

/*
게리맨더링 2
*/

int N, ans = 100 * 20 * 20 + 1;
int map[21][21], sum[6];

void divide(int x, int y, int d1, int d2) {
	int one = 1;
	int two = 1;
	int three = d2;
	int four = d1;

	memset(sum, 0, sizeof(sum));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 1번 선거구
			if (i < x && j <= y) {
				sum[1] += map[i][j];
			}
			else if (x <= i && i < x + d1 && j <= y - one) {
				sum[1] += map[i][j];
			}

			// 2번 선거구
			else if (i < x && y < j && j <= N) {
				sum[2] += map[i][j];
			}
			else if (x <= i && i <= x + d2 && y + two <= j && j <= N) {
				sum[2] += map[i][j];
			}
			
			// 3번 선거구
			else if (x + d1 <= i && i <= x + d1 + d2 && j < y + d2 - d1 - three) {
				sum[3] += map[i][j];
			}
			else if (x + d1 + d2 < i && i <= N && j < y + d2 - d1) {
				sum[3] += map[i][j];
			}

			// 4번 선거구
			else if (x + d2 < i && i <= x + d1 + d2 && y + d2 - d1 + four < j && j <= N) {
				sum[4] += map[i][j];
			}
			else if (i > x + d1 + d2 && y + d2 - d1 <= j && j <= N) {
				sum[4] += map[i][j];
			}

			// 5번 선거구
			else {
				sum[5] += map[i][j];
			}
		}

		if (x <= i) one++;
		if (x <= i) two++;
		if (x + d1 <= i) three--;
		if (x + d2 <= i) four--;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; x + d1 <= N - 2; d1++) {
				if (y - d1 < 1) break;
				for (int d2 = 1; x + d1 + d2 <= N; d2++) {
					if (y + d2 > N) break;

					// 선거구 나누기
					divide(x, y, d1, d2);

					// 인구 차이 구하기
					int vmax = sum[1];
					int vmin = sum[1];
					for (int i = 2; i <= 5; i++) {
						if (vmax < sum[i]) vmax = sum[i];
						if (vmin > sum[i]) vmin = sum[i];
					}
					ans = min(ans, vmax - vmin);
				}
			}
		}
	}

	cout << ans;
}


/*
// 선거구 번호별로 나누고 출력하는 테스트 함수
void divide(int x, int y, int d1, int d2) {
	int tmp[21][21];
	int one = 1;
	int two = 1;
	int three = d2;
	int four = d1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 1번 선거구
			if (i < x && j <= y) {
				tmp[i][j] = 1;
			}
			else if (x <= i && i < x + d1 && j <= y - one) {
				tmp[i][j] = 1;
			}

			// 2번 선거구
			else if (i < x && y < j && j <= N) {
				tmp[i][j] = 2;
			}
			else if (x <= i && i <= x + d2 && y + two <= j && j <= N) {
				tmp[i][j] = 2;
			}

			// 3번 선거구
			else if (x + d1 <= i && i <= x + d1 + d2 && j < y + d2 - d1 - three) {
				tmp[i][j] = 3;
			}
			else if (x + d1 + d2 < i && i <= N && j < y + d2 - d1) {
				tmp[i][j] = 3;
			}

			// 4번 선거구
			else if (x + d2 < i && i <= x + d1 + d2 && y + d2 - d1 + four < j && j <= N) {
				tmp[i][j] = 4;
			}
			else if (i > x + d1 + d2 && y + d2 - d1 <= j && j <= N) {
				tmp[i][j] = 4;
			}

			// 5번 선거구
			else {
				tmp[i][j] = 5;
			}
		}

		if (x <= i) one++;
		if (x <= i) two++;
		if (x + d1 <= i) three--;
		if (x + d2 <= i) four--;
	}

	cout << "(" << x << "," << y << ") d1=" << d1 << "d2=" << d2 << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
*/