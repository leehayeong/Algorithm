#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

/*
뱀
사과를 먹으면 뱀 길이가 늘어난다.
시작은 오른쪽을 보고 있다.
뱀이 벽 또는 몸과 부딪히면 게임이 끝난다. 몇 초에 끝나는가?
*/

int N, K, L, ans;
int map[100][100], visited[100][100];
int dx[4] = { -1, 0, 1, 0 };	// 북동남서
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, char>> cmd;
deque<pair<int, int>> snake;

int rot(int dir, char cmd) {
	if (cmd == 'L') {			// 왼쪽 90도 회전
		return (dir + 3) % 4;
	}
	else if (cmd == 'D') {		// 오른쪽 90도 회전
		return (dir + 1) % 4;
	}
}

// 현재 x, y, dir
void move(int x, int y, int dir, int cnt) {
	// 게임종료
	if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == 2) {
		ans = cnt;
		return;
	}

	// 사과 없으면 꼬리 지우기
	if (map[x][y] != 1) {
		int tx = snake.back().first;
		int ty = snake.back().second;
		map[tx][ty] = 0;
		snake.pop_back();
	}

	// 이동한 칸에 머리 놓기
	map[x][y] = 2;
    snake.push_front(make_pair(x, y));

	// 회전명령 있는지 판단
	if (!cmd.empty()) {
		int time = cmd.front().first;
		if (cnt == time) {							// 회전명령을 해야하는 초이면 회전
			dir = rot(dir, cmd.front().second);		// dir을 cmd에 따라 회전
			cmd.pop();
		}
	}

	// 다음 방향으로 이동
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	move(nx, ny, dir, cnt + 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	// 사과 위치
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}

	// 방향 변환
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x; char c;
		cin >> x >> c;
		cmd.push(make_pair(x, c));
	}

	// 시작은(0,0)에서 오른쪽방향으로
	map[0][0] = 2;
	snake.push_front(make_pair(0, 0));
	move(0 + dx[1], 0 + dy[1], 1, 1);

	cout << ans;
}