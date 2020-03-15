#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
로봇 시뮬레이션
로봇들을 움직일 때, 충돌 여부를 판단하라.
OK, 벽 충돌, 로봇끼리 충돌
*/

typedef struct {
	int x, y, dir;
}Robot;

int A, B, N, M;		// 가로, 세로, 로봇 수, 명령 수
int map[101][101];
Robot rlist[101];
int dx[4] = { -1, 0, 1, 0 };	// 북, 동, 남, 서
int dy[4] = { 0, 1, 0, -1 };

// return: 0 OK, -1 벽충돌, 1~N n번째 로봇과 충돌
int move(int n, Robot robot, char cmd, int cnt) {
	int go;	// 누적 회전횟수/이동횟수
	
	// 왼쪽 90도 회전 (방향만 변경)
	if (cmd == 'L') {
		int ndir;
		go = cnt % 4;	// 회전은 4번 주기로 같은방향
		ndir = (4 + robot.dir - go) % 4;
		rlist[n] = { robot.x, robot.y, ndir };
	}

	// 오른쪽 90도 회전 (방향만 변경)
	else if (cmd == 'R') {
		int ndir;
		go = cnt % 4;
		ndir = (robot.dir + go) % 4;
		rlist[n] = { robot.x, robot.y, ndir };
	}
	
	// 앞으로 한 칸 (좌표만 변경)
	else if (cmd == 'F') {
		int nx = robot.x, ny = robot.y, dir = robot.dir, go = 0;
		while (1) {
			if (go == cnt) break;
			nx += dx[dir];
			ny += dy[dir];
			if (nx <= 0 || nx > B || ny <= 0 || ny > A) return -1;	// 벽 충돌
			if (map[nx][ny] != 0) return map[nx][ny];				// 로봇 충돌
			go++;
		}
		swap(map[nx][ny], map[robot.x][robot.y]);
		rlist[n] = { nx, ny, dir };
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> N >> M;

	// 로봇 입력
	for (int i = 1; i <= N; i++) {
		Robot cur;	char d;	// 방향
		cin >> cur.x >> cur.y >> d;
		
		if (d == 'N') cur.dir = 0;
		else if (d == 'E') cur.dir = 1;
		else if (d == 'S') cur.dir = 2;
		else if (d == 'W') cur.dir = 3;
		cur.y = B - cur.y + 1;	// 좌표 조정 (왼쪽 하단이 1,1 가 되도록)

		map[cur.y][cur.x] = i;
		rlist[i] = { cur.y, cur.x, cur.dir };
	}

	// 명령 입력
	int ans;
	for (int i = 0; i < M; i++) {
		int n, cnt, ret;	char cmd; // 로봇 이름, 반복 횟수, 명령
		cin >> n >> cmd >> cnt;
		
		ans = move(n, rlist[n], cmd, cnt);

		if (ans == 0) {
			continue;
		}
		else if (ans == -1) {
			cout << "Robot " << n << " crashes into the wall";
			break;
		}
		else {
			cout << "Robot " << n << " crashes into robot " << ans;
			break;
		}
	}

	if (ans == 0) cout << "OK";
}