#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
적록색약
구역 = 같은 색, 상하좌우 인접 = 같은 구역
적록색약은 빨강,초록을 같은 색으로 봄
적록색약인 사람과 아닌 사람이보는 구역의 수는?
*/

int N;
char map[100][100];
bool visited[100][100], rgb_visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
			
			// 같은 색상 인접
			if (map[tx][ty] == map[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

void rgb_bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	rgb_visited[x][y] = true;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || rgb_visited[nx][ny]) continue;

			// 같은 색상, 빨 초 구분 X
			if (map[tx][ty] == map[nx][ny] || map[tx][ty] == 'R' && map[nx][ny] == 'G' || map[tx][ty] == 'G' && map[nx][ny] == 'R') {
				q.push(make_pair(nx, ny));
				rgb_visited[nx][ny] = true;
			}
		}
	}
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

	// 적록색약 X, 적록색약 O
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				cnt1++;
			}
			if (!rgb_visited[i][j]) {
				rgb_bfs(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2;
}