#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
사탕 게임
색이 다른 두 사탕을 교환했을 때 먹을 수 있는 최대 사탕 수는?
*/

int N;
char map[50][50], copyMap[50][50];
int dx[4] = { 0, 1 };	// 오른쪽, 아래로만 탐색하면 됨
int dy[4] = { 1, 0 };

int eat() {
	int vcnt, hcnt;
	int vmax = 1, hmax = 1;

	// 가로 최대 길이 찾기
	for (int i = 0; i < N; i++) {
		vcnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				vcnt++;
				vmax = max(vmax, vcnt);
			}
			else {
				vcnt = 1;
			}
		}
	}

	// 세로 최대 길이 찾기
	for (int i = 0; i < N; i++) {
		hcnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[j][i] == map[j + 1][i]) {
				hcnt++;
				hmax = max(hmax, hcnt);
			} else{
				hcnt = 1;
			}
		}
	}

	return max(vmax, hmax);
}

int move(int x, int y) {
	int ret = 0;

	// 인접 찾기
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;	// 범위 밖
		if (map[nx][ny] == map[x][y]) continue;					// 인접 칸의 사탕색이 같음

		swap(map[x][y], map[nx][ny]);	// 사탕 교환
		ret = max(ret, eat());			// 먹을 부분 찾기
		swap(map[nx][ny], map[x][y]);	// 사탕 복구
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

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, move(i, j));
		}
	}

	cout << ans;
}