#include <iostream> 
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ROW 12
#define COL 6
/*
puyo puyo
터지는 연쇄 횟수는?
*/

typedef struct {
	int x, y;
	char c;
}location;

char map[ROW][COL];
bool visited[ROW][COL];
int dx[4] = { -1, 1, 0, 0 };	
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y, char c) {
	queue<location> q;
	queue<location> wait;	// 터트릴 대기목록

	q.push({ x, y, c });
	visited[x][y] = true;
	wait.push({ x, y, c });

	while (!q.empty()) {
		location t = q.front();
		int tx = t.x;
		int ty = t.y;
		char tc = t.c;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL) continue;

			// 같은 알파벳이면 터트릴 대기큐에도 추가
			if (map[nx][ny] == tc && visited[nx][ny] == false) {
				q.push({ nx, ny, tc });
				visited[nx][ny] = true;
				wait.push({ nx, ny, tc });
			}
		}
	}

	// 같은 색 4개 이상이면
	if (wait.size() >= 4) {
		// 터트리기
		while (!wait.empty()) {
			map[wait.front().x][wait.front().y] = '.';
			wait.pop();
		}
		return 1;
	}

	return 0;
}

void gravity() {
	// 가장 마지막 행부터 탐색
	for (int j = 0; j < COL; j++) {
		int cur = 0;
		for (int i = ROW - 1; i >= 0; i--) {
			// 내려갈 가장 밑아래 위치 저장
			if (map[i][j] == '.') {
				if (cur == 0) cur = i;
				continue;
			}

			// 내려가기
			if (cur != 0 && map[i][j] != '.') {
				map[cur][j] = map[i][j];
				map[i][j] = '.';
				cur--;
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < ROW; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < COL; j++) {
			map[i][j] = s[j];
		}
	}

	int ans = 0;
	int tmp;	// 한 타임에 몇 번 터졌는지.
	do {
		tmp = 0;
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (map[i][j] != '.') {
					//cout << i << " " << j << "\n";
					tmp += bfs(i, j, map[i][j]);
				}
			}
			memset(visited, false, sizeof(visited));
		}

		if (tmp != 0) {
			// 연쇄 횟수 증가
			ans++;

			// 중력 적용
			gravity();
		}
	} while (tmp != 0);	// 한 타임에 한 번도 터진게 없다면, 계속 0을 반환했을 것. 0이면 종료

	cout << ans;
}