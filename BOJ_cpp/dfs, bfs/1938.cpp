#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
통나무 옮기기
L, R, U, D, T 명령 할 수 있음
BBB를 EEE로 옮기기까지 필요한 가장 최소 명령 수는?
*/

typedef struct {
	int x, y;	// 통나무 첫 좌표
	int dir;	// 가로 0, 세로 1
	int cnt;
}Log;

int N;
char map[50][50];
bool visited[50][50][2];	// 통나무 방향 
char cmd[5] = { 'L', 'R', 'U', 'D', 'T' };
Log B, E;

int bfs(int x, int y, int dir) {
	queue<Log> q;
	q.push(B);
	visited[x][y][dir] = true;

	while (!q.empty()) {
		Log cur = q.front();
		int tx = cur.x;
		int ty = cur.y;
		int tdir = cur.dir;
		int cnt = cur.cnt;
		q.pop();

		for (int i = 0; i < 5; i++) {
			int nx = tx;
			int ny = ty;
			int ndir = tdir;
			int cx, cy;	// 중심 좌표

			// 가로
			if (ndir == 0) {	
				// 범위확인
				if (cmd[i] == 'L') {
					ny--;
					if (ny < 0) continue;
				}
				else if (cmd[i] == 'R') {
					ny++;
					if (ny + 2 >= N) continue;
				}
				else if (cmd[i] == 'U') {
					nx--;
					if (nx < 0) continue;
				}
				else if (cmd[i] == 'D') {
					nx++;
					if (nx >= N) continue;
				}
				else if (cmd[i] == 'T') {	// 회전에 따른 범위 확인, 중심 좌표 구하기
					nx--;
					ny++;
					if (nx < 0 || nx + 2 >= N) continue;
					cx = tx;
					cy = ty + 1;
				}

				// 이동에 따른 범위 확인
				if (cmd[i] == 'L'){		
					if (map[nx][ny] == '1') continue;
				}
				else if (cmd[i] == 'R') {
					if (map[nx][ny + 2] == '1') continue;
				}
				else if (cmd[i] == 'U' || cmd[i] == 'D') {
					bool flag = false;
					for (int i = 0; i < 3; i++) {
						if (map[nx][ny + i] == '1') {
							flag = true;
							break;
						}
					}
					if (flag) continue;
				}
			}

			// 세로
			else if (ndir == 1) {
				// 범위 확인
				if (cmd[i] == 'L') {
					ny--;
					if (ny < 0) continue;
				}
				else if (cmd[i] == 'R') {
					ny++;
					if (ny >= N) continue;
				}
				else if (cmd[i] == 'U') {
					nx--;
					if (nx < 0) continue;
				}
				else if (cmd[i] == 'D') {
					nx++;
					if (nx + 2 >= N) continue;
				}
				else if (cmd[i] == 'T') {
					nx++;
					ny--;
					if (ny < 0 || ny + 2 >= N) continue;
					cx = tx + 1;
					cy = ty;
				}
				
				// 이동에 따른 범위 확인
				if (cmd[i] == 'L' || cmd[i] == 'R') {
					bool flag = false;
					for (int i = 0; i < 3; i++) {
						if (map[nx + i][ny] == '1') {
							flag = true;
							break;
						}
					}
					if (flag) continue;
				}
				else if (cmd[i] == 'U'){
					if (map[nx][ny] == '1') continue;
				}
				else if (cmd[i] == 'D') {
					if (map[nx + 2][ny] == '1') continue;
				}
			}

			// 회전은 가로, 세로 상관 없이 3*3 전체 이동 범위 확인해야 함
			if (cmd[i] == 'T') {
				// 중심좌표를 기준으로 나무 이동 확인
				bool flag = false;
				for (int i = cx - 1; i <= cx + 1; i++) {
					for (int j = cy - 1; j <= cy + 1; j++) {
						if (map[i][j] == '1') {
							flag = true;
							break;
						}
					}
					if (flag) break;
				}
				if (flag) continue;

				ndir = (ndir + 1) % 2;	// 회전시 방향 반전
			}

			// 이동 가능한 경우 큐에 push
			if (!visited[nx][ny][ndir]) {
				if (nx == E.x && ny == E.y && ndir == E.dir) {	// 이동끝나면 종료
					return cnt + 1;
				}
				q.push({ nx, ny, ndir, cnt + 1 });
				visited[nx][ny][ndir] = true;
			}
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	vector<pair<int, int>> b, e;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'B') b.push_back(make_pair(i, j));
			if (map[i][j] == 'E') e.push_back(make_pair(i, j));
		}
	}
	
	// 통나무 좌표, 방향 저장
	B.x = b[0].first, B.y = b[0].second;
	if (b[0].first == b[1].first) B.dir = 0;	// 같은 행이면 가로, 다른 행이면 세로
	else B.dir = 1;

	E.x = e[0].first, E.y = e[0].second;
	if (e[0].first == e[1].first) E.dir = 0;
	else E.dir = 1;

	cout << bfs(B.x, B.y, B.dir);
}