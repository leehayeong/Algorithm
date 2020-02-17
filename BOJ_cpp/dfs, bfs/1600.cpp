#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

/*
말이 되고픈 원숭이
말의 움직임을 보고 그대로 따라한다.

말이 움직일 수 있는 범위
위2+오1 / 위2+왼1 / 아래2+오1 / 아래2+왼1 / 
왼2+위1 / 왼2+아래1 / 오2+위1 / 오2+아래1

원숭이
k번만 말처럼 움직인다. 그 이후엔 인접 칸으로만. (대각선X)

맨왼쪽위에서 맨오른쪽아래까지. 도착지점까지 가는 최소 수?
0 = 평지, 1 = 장애물
*/

typedef struct {
	int x, y, k, cnt;
}location;

// 원숭이가 움직일 수 있는 횟수 K, 가로 W, 세로 H
int K, W, H;
int map[200][200];
bool visited[200][200][31];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int hx[8] = { 1, -1, 1, -1, -2, -2, 2, 2 };
int hy[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };

int bfs() {
	queue<location> q;
	
	// 0,0에서 시작
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 0;

	while (!q.empty()) {
		location t = q.front();
		int x = t.x;
		int y = t.y;
		int k = t.k;
		int c = t.cnt;
		q.pop();

		if (x == H - 1 && y == W - 1) {
			return c;
		}

		// 말처럼 움직일 수 있으면, 말처럼 움직이기
		if (k < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hx[i];
				int ny = y + hy[i];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

				// 갈 수 있는 곳이면 간다.
				if (map[nx][ny] == 0 && visited[nx][ny][k + 1] == false) {
					q.push({ nx, ny, k + 1, c + 1});
					visited[nx][ny][k + 1] = true;
				}
			}
		}

		// 4방향 탐색
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
				
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

			// 갈 수 있는 곳이면 간다.
			if (map[nx][ny] == 0 && visited[nx][ny][k] == false) {
				q.push({ nx, ny, k, c + 1});
				visited[nx][ny][k] = true;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	cout << bfs();
}