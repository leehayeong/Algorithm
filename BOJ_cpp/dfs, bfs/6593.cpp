#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
상범빌딩
정육면체 탈출하기(동,서,남,북,상,하) 최단시간
*/

typedef struct {
	int x, y, z;
}Location;

int L, R, C, ans;	// 층, 행, 열
char map[30][30][30];
int visited[30][30][30];
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int bfs(int x, int y, int z) {
	queue<Location> q;
	q.push({ x, y, z });
	visited[x][y][z] = 0;

	while (!q.empty()) {
		Location cur = q.front();
		int tx = cur.x;
		int ty = cur.y;
		int tz = cur.z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			int nz = tz + dz[i];

			if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny][nz] != -1) continue;
			
			if (map[nx][ny][nz] == '.') {
				q.push({ nx, ny, nz });
				visited[nx][ny][nz] = visited[tx][ty][tz] + 1;
			}

			else if (map[nx][ny][nz] == 'E') {
				return visited[tx][ty][tz] + 1;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		Location s;
		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') s = { i, j, k };
				}
			}
		}

		memset(visited, -1, sizeof(visited));
		ans = bfs(s.x, s.y, s.z);
		if (ans == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}
}