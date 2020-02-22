#include <iostream> 
#include <queue>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

/*
로봇
출발지에서 도착지 갈 때 로봇의 이동 횟수와 회전 횟수는?
*/

typedef struct {
	int x, y, dir;
}robot;

int M, N;
int a, b, dir1, c, d, dir2;
int map[100][100];
int visited[100][100][4];
int dx[4] = { 0, 0, 1, -1 };	// 동0 서1 남2 북3 순서
int dy[4] = { 1, -1, 0, 0 };

// 동0->서1 = 2회전, 서1->동0 = 2회전, 남2->북3 = 2회전, 북3->남2 = 2회전
int rot(int cur, int next) {
	if (cur == next) return 0;
	if (cur == 0 && next == 1) return 2;
	if (cur == 1 && next == 0) return 2;
	if (cur == 2 && next == 3) return 2;
	if (cur == 3 && next == 2) return 2;
	return 1;
}

int bfs(int x, int y, int dir) {
	queue<robot> q;

	q.push({ x, y, dir });
	visited[x][y][dir] = 0;

	int ans = INT_MAX;
	while (!q.empty()) {
		robot t = q.front();
		int tx = t.x;
		int ty = t.y;
		int tdir = t.dir;
		q.pop();

		// 도착지에 도착하면, 방향 확인 후 회전 필요하면 회전
		if (tx == c && ty == d) {
			if (tdir != dir2) {
				visited[tx][ty][dir2] = visited[tx][ty][tdir] + rot(tdir, dir2);
			}
			ans = min(ans, visited[c][d][dir2]);
			continue;
		}

		// 회전 + 이동
		for (int i = 0; i < 4; i++) {
			int ndir = i;
			int ncnt = visited[tx][ty][tdir] + rot(tdir, ndir) + 1;	// 현재까지 횟수 + 회전 횟수 + 이동 횟수

			for (int k = 1; k <= 3; k++) {
				int nx = tx + dx[i] * k;
				int ny = ty + dy[i] * k;

				// 범위를 벗어나거나, 벽에 부딪히면 더이상 갈 수 없으므로 빠져나옴
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[nx][ny] == 1) break;

				// 이 경로가 현재 저장되어 있는 값보다 최솟값이면 업데이트
				if (visited[nx][ny][ndir] == 0 || ncnt < visited[nx][ny][ndir]) {
					q.push({ nx, ny, ndir });
					visited[nx][ny][ndir] = ncnt;
				}
			}
		}
	}

	return ans;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	cin >> a >> b >> dir1;	// 출발
	cin >> c >> d >> dir2;	// 도착

	a--; b--; dir1--;
	c--; d--; dir2--;
	cout << bfs(a, b, dir1);
}