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

풀이 2: ㅗ, ㅜ, ㅓ, ㅏ 모양은 좌표와 직접 대칭, 나머지 모양은 DFS로 탐색
*/

int N, M, ans;
int map[500][500];
int visited[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 나머지 블록은 dfs로 깊이가 4일 때까지 4방향 탐색. 
// 모든 블록의 경우의 수를 찾을 수 있음
void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) continue;
		visited[nx][ny] = true;
		dfs(nx, ny, cnt + 1, sum + map[nx][ny]);
		visited[nx][ny] = false;
	}
}

// ㅜ ㅏ ㅓ ㅗ 는 dfs가 아닌 별도의 방법으로 찾아야 함
// 2*3 배열로 보고 (0,0) 지점을 기준으로 계산
void calPlus(int x, int y) {
	// ㅜ
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
	}
	// ㅗ
	if (y + 2 < M && x + 1 < N) {
		ans = max(ans, map[x][y + 1] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2]);
	}
	// ㅓ
	if (y + 1 < M && x + 2 < N) {
		ans = max(ans, map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1] + map[x + 2][y + 1]);
	}
	// ㅏ
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
			visited[i][j] = true;
			dfs(i, j, 1, map[i][j]);
			visited[i][j] = false;
			calPlus(i, j);
		}
	}

	cout << ans;
}