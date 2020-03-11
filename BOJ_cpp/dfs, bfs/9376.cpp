#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
탈옥
죄수 두명이 탈옥하기 위해 열어야하는 최소 문의 수는?
*/

typedef struct {
	int x, y, cnt;
}Point;

struct compare {
	bool operator()(Point a, Point b) {
		return a.cnt > b.cnt;
	}
};

int H, W;
char map[102][102];
int visited[102][102][3];	// 죄수1, 죄수2, 바깥에서 안으로 진입 시 여는 문의 수를 각각 3차원 배열로.
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void bfs(Point person, int idx) {
	priority_queue<Point, vector<Point>, compare> q;	// 문을 최소로 열기 위해 pq 사용
	q.push(person);
	visited[person.x][person.y][idx] = 0;

	while (!q.empty()) {
		Point cur = q.top();
		int x = cur.x;
		int y = cur.y;
		int cnt = cur.cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= H + 2 || ny < 0 || ny >= W + 2) continue;

			if (map[nx][ny] == '*') continue;	// 벽이면 다음으로

			if (visited[nx][ny][idx] == -1) {
				if (map[nx][ny] == '.') {
					q.push({ nx, ny, cnt });
					visited[nx][ny][idx] = visited[x][y][idx];
				}
				else if (map[nx][ny] == '#') {
					q.push({ nx, ny, cnt + 1 });
					visited[nx][ny][idx] = visited[x][y][idx] + 1;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> H >> W;
		// 경우3을 위해 맵 확장
		for (int i = 0; i < H + 2; i++) {
			for (int j = 0; j < W + 2; j++) {
				if (i == 0 || i == H + 1 || j == 0 || j == W + 1) {
					map[i][j] = '.';
					continue;
				}
			}
		}

		Point person[3];
		int k = 0;
		for (int i = 1; i < H + 1; i++) {
			string s;
			cin >> s;
			for (int j = 1; j < W + 1; j++) {
				map[i][j] = s[j - 1];
				if (map[i][j] == '$') {
					map[i][j] = '.';
					person[k] = { i, j, 0 };
					k++;
				}
			}
		}
		person[k] = { 0, 0, 0 };

		// 1. 죄수1, 2. 죄수2, 3. 외부(0,0)->안 으로 들어가는 경우를 3개로 나누어 각각 bfs 진행
		memset(visited, -1, sizeof(visited));
		for (int k = 0; k < 3; k++) {
			bfs(person[k], k);
		}

		// 세 경우를 모두 더하고 최솟값 찾기. 
		// 단, 세 경우를 모두 더했을 때 더한 지점이 문이라면, 문은 한 번만 열면 되므로 -2 할 것
		int ans = 1000000000;
		for (int i = 1; i < H + 1; i++) {
			for (int j = 1; j < W + 1; j++) {
				if (map[i][j] == '*') continue;
				int sum = visited[i][j][0] + visited[i][j][1] + visited[i][j][2];
				if (map[i][j] == '#') sum = sum - 2;
				ans = min(ans, sum);
			}
		}

		cout << ans << "\n";
	}
}