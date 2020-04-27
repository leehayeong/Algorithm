#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

/*
낚시왕
*/

typedef struct {
	int x, y;
	int s, dir, z;
}Shark;

int R, C, M;
int map[101][101], copyMap[101][101];
Shark sharkList[10001]; bool catched[10001];
int dx[5] = { 0, -1, 1, 0, 0 };	// 1위, 2아래, 3오, 4왼
int dy[5] = { 0, 0, 0, 1, -1 };
int score, cnt;

int changeDir(int dir) {
	if (dir == 1) return 2;
	if (dir == 2) return 1;
	if (dir == 3) return 4;
	if (dir == 4) return 3;
	return 0;
}

void moveShark() {
	memset(copyMap, 0, sizeof(copyMap));

	for (int i = 1; i <= M; i++) {
		if (catched[i]) continue;	// 이미 잡은 상어

		Shark cur = sharkList[i];
		int x, y, s, dir, z;
		x = cur.x; y = cur.y; s = cur.s; dir = cur.dir; z = cur.z;
		map[x][y] = 0;

		// 방향에 따라 x 또는 y만 update
		int nx = x, ny = y;
		if (dir == 1 || dir == 2) {
			// 반복되기 때문에 나머지 연산으로 제한
			int move = s % ((R - 1) * 2);

			for (int k = 0; k < move; k++) {
				nx += dx[dir];

				// 왼쪽 벽에 부딪히면 방향 전환
				if (nx < 1) {
					dir = changeDir(dir);
					nx = 2;
				}
				// 오른족 벽에 부딪히면 방향 전환
				else if (nx > R) {
					dir = changeDir(dir);
					nx = R - 1;
				}
			}
		}
		else if (dir == 3 || dir == 4) {
			int move = s % ((C - 1) * 2);

			for (int k = 0; k < move; k++) {
				ny += dy[dir];

				if (ny < 1) {
					dir = changeDir(dir);
					ny = 2;
				}
				else if (ny > C) {
					dir = changeDir(dir);
					ny = C - 1;
				}
			}
		}

		// 이미 상어가 있으면 (상어의 이동은 동시에 이루어지기 때문에 map 분리)
		if (copyMap[nx][ny] != 0) {
			int n = copyMap[nx][ny];
			// 내가 더 큼 = 이미 있는 애를 잡아먹음
			if (sharkList[n].z < z) {
				catched[n] = true;
			}
			// 이미 있는 애가 더 큼 = 내가 잡아먹힘
			else {
				catched[i] = true;
				continue;
			}
		}

		// 맵과 상어 이동한 곳으로 update
		copyMap[nx][ny] = i;
		sharkList[i] = { nx, ny, s, dir, z };
	}
	
	// 맵에 이동한 상어 적용
	for (int i = 1; i <= M; i++) {
		if (catched[i]) continue;
		map[sharkList[i].x][sharkList[i].y] = i;
	}
}

void catchShark(int y) {
	// 땅과 가장 가까운 상어 찾기
	int n = 1;
	while (n <= R && map[n][y] == 0) n++;
	if (n > R) return;

	// 상어 잡음
	int shark = map[n][y];
	score += sharkList[shark].z;
	catched[shark] = true;
	map[n][y] = 0;
	cnt++;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;	// 위치, 속력, 이동방향, 크기
		cin >> r >> c >> s >> d >> z;
		sharkList[i] = { r, c, s, d, z };
		map[r][c] = i;
	}

	// 낚시왕 1열부터 C열까지 이동하면서 낚시 시작
	for (int i = 1; i <= C; i++) {
		if (cnt == M) break;	// 상어 다 잡음
		catchShark(i);	// 상어 잡고
		moveShark();	// 상어 이동	
	}

	cout << score;
}

/*
출력 테스트 코드
void printMap() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

	for (int i = 1; i <= C; i++) {
		if (cnt == M) break;	// 상어 다 잡음

		cout << i << "초\n";
		catchShark(i);	// 상어 잡고

		cout << "잡은후\n";
		printMap();

		moveShark();	// 상어 이동

		cout << "상어이동후\n";
		printMap();
	}
*/