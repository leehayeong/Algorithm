#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
벽 부수고 이동하기
(1,1)에서 (N,M)까지 벽을 한개까지 부수고 이동할 수 있다.
0이면 이동할 수 있는 곳, 1이면 벽이어서 이동할 수 없는 곳
최단거리는? (불가능할 때는 -1)
*/

int N, M;
int map[1001][1001];
int checked[1001][1001][2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;

	// 첫 상태는 벽을 부수지 않은 상태 (부수면 1, 아니면 0)
	q.push(make_pair(make_pair(x, y), 0));
	checked[x][y][0] = 1;
	
	while (!q.empty()) {
		// x, y, 벽 부수었는지 상태
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int check = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;

			// 이동할 수 있는 곳이고, 방문하지 않았다면 그대로 탐색
			if (map[nx][ny] == 0 && checked[nx][ny][check] == 0) {
				q.push(make_pair(make_pair(nx, ny), check));
				checked[nx][ny][check] = checked[tx][ty][check] + 1;
			}

			// 이동할 수 없는 곳이고, 아직 벽도 부수지 않았다면 벽 부수고 탐색하기
			if (map[nx][ny] == 1 && check == 0) {
				q.push(make_pair(make_pair(nx, ny), 1));
				checked[nx][ny][1] = checked[tx][ty][check] + 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			map[i][j] = s[j - 1] - '0';
		}
	}

	bfs(1, 1);
	
	if (checked[N][M][0] == 0 && checked[N][M][1] == 0) cout << "-1";
	else if (checked[N][M][0] == 0) cout << checked[N][M][1];
	else if (checked[N][M][1] == 0) cout << checked[N][M][0];
	else cout << min(checked[N][M][0], checked[N][M][1]);
}