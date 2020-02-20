#include <iostream> 
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

/*
탈출
고슴도치S가 물*에 잠기지 않고 비버의굴D로 가는 최단경로는?
*/

int R, C;
char map[50][50];
int visited[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

typedef struct {
	int x, y;
	char c;
}location;

int bfs(int x, int y, int a, int b) {
	// 물 위치와 고슴도치 위치 넣을 큐 선언
	queue<location> q;

	// 물 위치 먼저 모두 push
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				q.push({ i, j, '*' });
			}
		}
	}

	// 고슴도치 push
	q.push({ x, y, 'S' });
	visited[x][y] = 1;

	while (!q.empty()) {
		location t = q.front();
		int tx = t.x;
		int ty = t.y;
		char c = t.c;
		q.pop();

		// 비버의 굴 도착
		if (tx == a && ty == b) return visited[tx][ty] - 1;
		
		// 물이면, 퍼져나가므로 맵을 물로 변경
		if (c == '*') {
			for (int i = 0; i < 4; i++) {
				int nx = tx + dx[i];
				int ny = ty + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >=C) continue;

				// 물이 갈 수 있는 곳은 비어있는 곳과 고슴도치가 있는 위치
				if (map[nx][ny] == '.' || map[nx][ny] == 'S' ) {
					map[nx][ny] = '*';
					q.push({ nx, ny, '*' });
				}
			}
		}

		// 고슴도치면 visited 배열에 시간 저장
		else if (c == 'S') {
			for (int i = 0; i < 4; i++) {
				int nx = tx + dx[i];
				int ny = ty + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

				// 고슴도치가 갈 수 없는 곳은 물과 돌
				if ((map[nx][ny] != '*' && map[nx][ny] != 'X') && visited[nx][ny] == 0) {
					visited[nx][ny] = visited[tx][ty] + 1;
					q.push({ nx, ny, 'S' });
				}
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	int x, y, a, b;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			map[i][j] = s[j];
			
			// 고슴도치 위치 저장
			if (s[j] == 'S') {
				x = i; y = j;
			}

			// 비버의 굴 위치 저장
			else if (s[j] == 'D') {
				a = i; b = j;
			}
		}
	}

	int ans = bfs(x, y, a, b);
	if (ans == -1) cout << "KAKTUS";
	else cout << ans;
}