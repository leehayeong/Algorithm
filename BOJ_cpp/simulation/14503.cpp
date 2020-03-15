#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
로봇 청소기
*/

int N, M;
int map[50][50];
bool visited[50][50];
int dx[4] = { -1, 0, 1, 0 };	// 북, 동, 남, 서
int dy[4] = { 0, 1, 0, -1 };

int move(int x, int y, int dir) {
	visited[x][y] = true;
	int tx = x;
	int ty = y;
	int tdir = dir;
	int cnt = 1;
	int rotate = 0;

	while(1) {
		// 네 방향 모두 청소 되어있거나 벽이어서 갈 수 없으면 후진, 회전 수 초기화
		if (rotate == 4) {
			tx = tx - dx[tdir];
			ty = ty - dy[tdir];
			rotate = 0;

			// 후진 할 곳이 벽면 종료
			if (map[tx][ty] == 1) break;			
		}

		// 다음 탐색 할 왼쪽 방향 설정
		int left = (tdir + 3) % 4;
		int nx = tx + dx[left];
		int ny = ty + dy[left];

		// 청소할 공간이 없다면 회전만 (벽이거나, 방문했으면)
		if (map[nx][ny] == 1 || visited[nx][ny]) {
			rotate++;
			tdir = left;
			continue;
		}

		// 청소할 공간이 있다면 (벽이 아니고 방문하지 않았으면)
		tdir = left;			// 1. 왼쪽으로 회전			
		tx = nx;				// 2. 다음 위치 설정
		ty = ny;
		visited[nx][ny] = true;	// 3. 청소
		cnt = cnt + 1;			// 4. 청소 수 증가
		rotate = 0;				// 5. 회전 수 초기화
	}

	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y, dir;
	cin >> N >> M >> x >> y >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	cout << move(x, y, dir);
}