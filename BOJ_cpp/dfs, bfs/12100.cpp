#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
2048(Easy)
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록은?
왼쪽 0, 오른쪽 1, 위 2, 아래 3
*/

int N;
int map[20][20];

void move(int dir) {
	queue<int> q;		

	// 왼쪽
	if (dir == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 숫자가 적힌 값들 저장
				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}

			// 꺼내면서 비교
			int idx = 0;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[i][idx] == 0) {
					map[i][idx] = cur;
				}
				else if (map[i][idx] == cur) {	// 현재 2배하고, 다음에 저장할 수 있도록 idx 증가
					map[i][idx] *= 2;
					idx++;
				}
				else if (map[i][idx] != cur) {	// 겹치지 않게 하기 위해 idx 증가해서 다음 칸에 저장되도록함
					idx++;
					map[i][idx] = cur;
				}
			}
		}
	}

	// 오른쪽
	else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}

			int idx = N - 1;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[i][idx] == 0) {
					map[i][idx] = cur;
				}
				else if (map[i][idx] == cur) {
					map[i][idx] *= 2;
					idx--;
				}
				else if (map[i][idx] != cur) {
					idx--;
					map[i][idx] = cur;
				}
			}
		}
	}

	// 위
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[j][i] != 0) {
					q.push(map[j][i]);
					map[j][i] = 0;
				}
			}

			int idx = 0;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[idx][i] == 0) {
					map[idx][i] = cur;
				}
				else if (map[idx][i] == cur) {
					map[idx][i] *= 2;
					idx++;
				}
				else if (map[idx][i] != cur) {
					idx++;
					map[idx][i] = cur;
				}
			}
		}
	}

	// 아래
	else if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[j][i] != 0) {
					q.push(map[j][i]);
					map[j][i] = 0;
				}
			}
			
			int idx = N - 1;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[idx][i] == 0) {
					map[idx][i] = cur;
				}
				else if (map[idx][i] == cur) {
					map[idx][i] *= 2;
					idx--;
				}
				else if (map[idx][i] != cur) {
					idx--;
					map[idx][i] = cur;
				}
			}
		}
	}
}

int dfs(int cnt) {
	int ret = 0;

	if (cnt == 5) {
		// max 구하고 종료
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret = max(ret, map[i][j]);
			}
		}
		return ret;
	}

	// copyMap에 원본 상태 저장하고 원본으로 조작
	int copyMap[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copyMap[i][j] = map[i][j];
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		move(dir);
		ret = max(ret, dfs(cnt + 1));

		// 맵 복구
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = copyMap[i][j];
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0);
}