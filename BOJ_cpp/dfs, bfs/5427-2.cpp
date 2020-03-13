#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
불
상근이가 불을 피해 탈출할 수 있는 가장 빠른 시간은?
(벽에는 불이 붙지 않는다)

풀이 2. 불을 먼저 퍼트리고, 상근이를 이동시킨다.
*/

int W, H;
char map[1000][1000];
int visited[1000][1000];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int INF = 1000000000;

int bfs(vector<pair<int, int>> fire, pair<int, int> sg) {
	queue<pair<pair<int, int>, char>> q;	// 불인지 상근인지 구분하는 char

	// 불 먼저 push
	int fsize = fire.size();
	for (int i = 0; i < fsize; i++) {
		q.push(make_pair(fire[i], 'f'));
	}

	// 상근이 push
	q.push(make_pair(sg, 's'));
	visited[sg.first][sg.second] = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		char type = q.front().second;
		q.pop();
		
		// 불이면, 퍼져나가므로 맵을 불로 변경
		if (type == 'f') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

				// 벽이 아니면 불 확산
				if (map[nx][ny] == '.' || map[nx][ny] == '@') {
					map[nx][ny] = '*';
					q.push(make_pair(make_pair(nx, ny), type));
				}
			}
		}

		// 상근이면, 벽과 불이 아닌 곳으로 이동
		else if (type == 's') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				// 범위 밖으로 나오면 탈출 성공
				if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
					return visited[x][y] + 1;
				}

				// 벽과 물이 아니면 이동
				if (map[nx][ny] == '.' && visited[nx][ny] == -1) {
					q.push(make_pair(make_pair(nx, ny), type));
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> W >> H;

		vector<pair<int, int>> fire;	// 초기 불의 위치
		pair<int, int> sg;				// 상근이 초기 위치
		for (int i = 0; i < H; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < W; j++) {
				map[i][j] = s[j];
				if (map[i][j] == '*') fire.push_back(make_pair(i, j));
				if (map[i][j] == '@') sg = make_pair(i, j);
			}
		}

		// 불 확산
		memset(visited, -1, sizeof(visited));
		int ans = bfs(fire, sg);

		if (ans == 0) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
	}
}