#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
보물섬
상하좌우, 육지(L)로만 이동 가능. 바다는 (W)
보물이 묻혀있는 두 곳을 이동하는 최단시간은?

시작점마다 최대거리 갱신
*/

int N, M, ans;
char map[100][100];
int visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 0;
	int ret = 0;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] != -1) continue;
			
			if (map[tx][ty] == map[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[tx][ty] + 1;
				ret = max(ret, visited[nx][ny]);
			}
		}
	}

	return ret;
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
			if (map[i][j] == 'L') {
				memset(visited, -1, sizeof(visited));
				ans = max(ans, bfs(i, j));
			}
		}
	}

	cout << ans;
}