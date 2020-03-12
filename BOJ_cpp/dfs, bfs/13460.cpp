#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
구슬탈출 2
빨간 구슬이 구멍으로 10번 회전 내에 빠질 수 있으면 최소 횟수 출력, 없으면 -1
*/

typedef struct {
	int x, y;
}Point;

typedef struct {
	Point red, blue;
	int dir, cnt;
}Location;

int N, M;
char map[10][10];
int dx[4] = { 0, 0, -1, 1 };	// 왼 오 위 아래
int dy[4] = { -1, 1, 0, 0 };

// 움직인 지점과, 구멍에 빠졌는지 여부 리턴
pair<Point, bool> move(Point p, int dir) {
	int x = p.x;
	int y = p.y;
	int flag = false;
	while (1) {
		if (dir == 0) y--;		// 왼
		else if (dir == 1) y++;	// 오
		else if (dir == 2) x--;	// 위
		else if (dir == 3) x++;	// 아래

		if (map[x][y] == 'O') {
			flag = true;
			break;
		}
		if (map[x][y] == '#') {
			// 벽으로 막히면 막히기 전으로 back
			if (dir == 0) y++;
			else if (dir == 1) y--;
			else if (dir == 2) x++;
			else if (dir == 3) x--;
			break;
		}
	}

	Point ret = { x, y };
	return make_pair(ret, flag);
}

int bfs(Point r, Point b) {
	queue<Location> q;	// 빨간구슬, 파란구슬, 방향, cnt
	q.push({ r, b, -1, 0 });

	while (!q.empty()) {
		Location cur = q.front();
		Point red = cur.red;
		Point blue = cur.blue;
		int dir = cur.dir;
		int cnt = cur.cnt;
		q.pop();
		
		// 온 방향은 제외하고 탐색
		for (int i = 0; i < 4; i++) {
			if (i == dir || cnt == 10) continue;

			// 구슬 이동
			pair<Point, bool> rr, bb;
			Point nr, nb;
			bool flag_r, flag_b;

			rr = move(red, i);	// 빨간구슬 이동
			nr = rr.first;
			flag_r = rr.second;

			bb = move(blue, i);	// 파란 구슬 이동
			nb = bb.first;
			flag_b = bb.second;

			if (flag_r && !flag_b) return cnt + 1;	// 빨간 구슬만 구멍에 들어가면 종료
			if (flag_r && flag_b) continue;		// 두 구슬 모두 구멍에 들어가면 다음 (안되는 경우)
			if (flag_b) continue;				// 파란 구슬만 구멍에 들어가면 다음

			// 두 구슬이 겹치면 분리 (왼,오,위,아래)
			if (nr.x == nb.x && nr.y == nb.y) {
				if (i == 0) {
					if (red.y < blue.y) nb.y++;
					else nr.y++;
				}
				else if (i == 1) {
					if (red.y < blue.y) nr.y--;
					else nb.y--;
				}
				else if (i == 2) {
					if (red.x < blue.x) nb.x++;
					else nr.x++;
				}
				else if (i == 3) {
					if (red.x < blue.x) nr.x--;
					else nb.x--;
				}
			}

			// 구슬 이동이 없으면 그만
			if (red.x == nr.x && red.y == nr.y && blue.x == nb.x && blue.y == nb.y) continue;

			q.push({ nr, nb, i, cnt + 1 });
		}	
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	Point red, blue;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'R') {
				red = { i, j };
			}
			else if (map[i][j] == 'B') {
				blue = { i, j };
			}
		}
	}

	cout << bfs(red, blue);
}