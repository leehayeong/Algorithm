#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
테트로미노
테트로미노 하나를 적절히 놓아서 놓인 칸에 쓰여있는 수들의 합을 최대로 하라.
회전, 대칭 가능

풀이 1: 모든 경우의 수 좌표 직접 비교
*/

int N, M, ans;
int map[500][500];
int visited[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void calSum(int x, int y) {
	// o o
	// o o
	if (y + 1 < M && x + 1 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1]);
	}

	// o o o o
	if (y + 3 < M) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3]);
	}

	// o
	// o
	// o
	// o
	if (x + 3 < N) {
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y]);
	}

	// o
	// o
	// o o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 2][y + 1]);
	}

	//   o
	//   o
	// o o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y] + map[x + 2][y + 1]);
	}

	// o o o
	// o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y]);
	}

	// o
	// o o o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	// o o
	//   o
	//   o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1]);
	}

	// o o
	// o
	// o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x + 2][y]);
	}

	//     o
	// o o o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y + 2] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	// o o o
	//     o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 2]);
	}

	// o
	// o o
	//   o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y + 1]);
	}

	//   o
	// o o
	// o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y]);
	}

	//   o o
	// o o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x + 1][y] + map[x + 1][y + 1] + map[x][y + 1] + map[x][y + 2]);
	}

	// o o
	//   o o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	//   o
	// o o o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}

	// o o o
	//   o
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
	}

	//   o
	// o o
	//   o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1]);
	}
	// o
	// o o
	// o
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			calSum(i, j);
		}
	}

	cout << ans;
}