#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

/*
미세먼지 안녕!
*/

int R, C, T, ans;
int map[50][50];
int spreadMap[50][50];
int dx[4] = { -1, 0, 1, 0 };	// 북동남서
int dy[4] = { 0, 1, 0, -1 };

// 미세먼지 확산
void spread() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) {
				int cal = map[i][j] / 5;
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					// 범위밖
					if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == -1) continue;
					// 확산
					spreadMap[nx][ny] += cal;
					cnt++;
				}
				map[i][j] -= cal * cnt;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += spreadMap[i][j];
			spreadMap[i][j] = 0;
		}
	}
}

void clean(int spot) {
	// 아래쪽 회전 (시계) ↑ ← ↓ →
	for (int x = spot + 2; x < R; x++) map[x - 1][0] = map[x][0];
	for (int y = 1; y < C; y++) map[R - 1][y - 1] = map[R - 1][y];
	for (int x = R - 2; x >= spot; x--) map[x + 1][C - 1] = map[x][C - 1];
	for (int y = C - 2; y >= 1; y--) map[spot][y + 1] = map[spot][y];
	map[spot][1] = 0;

	// 위쪽 회전 (반시계) ↓ ← ↑ →
	spot--;
	for (int x = spot - 2; x >= 0; x--) map[x + 1][0] = map[x][0]; 
	for (int y = 1; y < C; y++) map[0][y - 1] = map[0][y];
	for (int x = 1; x <= spot; x++) map[x - 1][C - 1] = map[x][C - 1];
	for (int y = C - 2; y >= 1; y--) map[spot][y + 1] = map[spot][y]; 
	map[spot][1] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> T;
	int spot;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) spot = i;	// 공기청정기 위치한 y열 저장
		}
	}

	while (T--) {
		spread();			// 미세먼지 확산
		clean(spot);		// 공기청정기 작동
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}

	cout << ans;
}