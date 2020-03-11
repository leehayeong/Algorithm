#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
욕심쟁이 판다
대나무를 다 먹으면 상, 하, 좌, 우 이동 
다음 대나무가 지금 대나무보다 많아야 하며, 그렇지 않은 경우는 죽음
판다가 가장 오래 살 수 있는 일수는? 

dp[i][j] = (i, j)에서 판다가 출발했을 때 살 수 있는 최대 일수
*/

int N;
int map[500][500], dp[500][500];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<pair<int, pair<int, int>>> v;	// 값, 좌표

int dfs(int x, int y) {
	if (dp[x][y] != 0) return dp[x][y];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (map[nx][ny] > map[x][y]) {
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}
	}

	return dp[x][y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			v.push_back(make_pair(map[i][j], make_pair(i, j)));
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// dp 배열에 방문 일수를 채우지 않은 곳에 대해서만 탐색
			if (dp[i][j] == 0) {
				ans = max(ans, dfs(i, j));
			}
		}
	}
	cout << ans + 1;
}