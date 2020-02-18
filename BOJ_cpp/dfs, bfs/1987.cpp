#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

/*
알파벳
한 번 지나온 알파벳 다시 방문 X
좌측 상단에서 시작, 말이 지날 수 있는 최대 칸 수?
*/

int R, C, result;
int map[20][20];
bool visited[24];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int y, int x, int cnt) {
	// 인접 방향 탐색
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int ncnt = cnt + 1;

		if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;

		if (!visited[map[ny][nx]]) {
			visited[map[ny][nx]] = true;
			dfs(ny, nx, ncnt);
			visited[map[ny][nx]] = false;
		}
	}

	// 탐색이 끝나면 종료 시점까지 cnt 확인 가능.
	// 최댓값 찾기
	result = max(result, cnt);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < C; j++) {
			map[i][j] = t[j] - 'A';
		}
	}

	// 0,0부터 시작
	visited[map[0][0]] = true;
	dfs(0, 0, 1);

	cout << result;
}