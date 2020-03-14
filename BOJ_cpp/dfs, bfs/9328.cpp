#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
열쇠
상근이가 열쇠를 가지고 문을 열어 훔칠 수 있는 문서의 최대 개수는?
*/

int H, W;
char map[102][102];
bool key[26];	// 열쇠 가졌는지?
bool visited[102][102];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int x, int y) {
	queue <pair<int, int>> q;		// 상근이 이동 위치
	q.push(make_pair(0, 0));
	visited[x][y] = true;

	queue<pair<int, int>> door[26];	// 문 위치 저장
	int ret = 0;					// 훔칠 수 있는 문서 수
	
	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= H + 2 || ny < 0 || ny >= W + 2) continue;

			if (!visited[nx][ny]) {
				// 빈 곳
				if (map[nx][ny] == '.') {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}

				// 열쇠
				else if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
					//열쇠 획득
					key[map[nx][ny] - 'a'] = true;
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;

					// 열 수 있는 문으로 이동하도록 큐에 push
					while (!door[map[nx][ny] - 'a'].empty()) {
						pair<int, int> next = door[map[nx][ny] - 'a'].front();
						door[map[nx][ny] - 'a'].pop();
						q.push(next);
						visited[next.first][next.second] = true;
					}
				}

				// 문
				else if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
					// 열쇠를 가지고 있으면 push
					if (key[map[nx][ny] - 'A']) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
					// 열쇠가 없으면 문 위치 저장
					else {
						door[map[nx][ny] - 'A'].push(make_pair(nx, ny));
					}
				}

				// 문서
				else if (map[nx][ny] == '$') {
					ret++;
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		memset(key, false, sizeof(key));
		memset(visited, false, sizeof(visited));

		cin >> H >> W;
		// 건물 밖에서 바로 문을 열 수 있으므로, 맵 가장자리 '.'으로 확장}
		for (int i = 0; i < H + 2; i++) {
			map[i][0] = '.';
			map[i][W + 1] = '.';
		}
		for (int j = 0; j < W + 2; j++) {
			map[0][j] = '.';
			map[H + 1][j] = '.';
		}
		for (int i = 1; i < H + 1; i++) {
			string s;
			cin >> s;
			for (int j = 1; j < W + 1; j++) {
				map[i][j] = s[j - 1];
			}
		}

		string tkey;
		cin >> tkey;
		for (int i = 0; i < tkey.length(); i++) {
			if (tkey[i] == 0) break;
			key[tkey[i] - 'a'] = true;
		}

		cout << bfs(0, 0) << "\n";
	}
}