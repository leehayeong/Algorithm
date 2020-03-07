#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
주사위굴리기
이동할때마다 주사위 윗 면에 쓰여있는 수 출력
동 1 서 2 북 3 남 4

주사위를 놓은 곳 = 바닥
dict[0] = 뒤, [1] = 위, [2] = 앞, [3] = 바닥, [4] = 왼, [5] = 오
*/

int N, M, K;
int map[20][20];
int dice[6];

void east() {
	int tmp = dice[1];
	dice[1] = dice[4], dice[4] = dice[3], dice[3] = dice[5], dice[5] = tmp;
}

void west() {
	int tmp = dice[1];
	dice[1] = dice[5], dice[5] = dice[3], dice[3] = dice[4], dice[4] = tmp;
}

void north() {
	int tmp = dice[0];
	dice[0] = dice[1], dice[1] = dice[2], dice[2] = dice[3], dice[3] = tmp;
}

void south() {
	int tmp = dice[3];
	dice[3] = dice[2], dice[2] = dice[1], dice[1] = dice[0], dice[0] = tmp;
}

void simulation(int x, int y, int dir) {
	// 굴리기
	if (dir == 1) east();
	else if (dir == 2) west();
	else if (dir == 3) north();
	else if (dir == 4) south();

	// 바닥 수 update
	if (map[x][y] == 0) {
		map[x][y] = dice[3];	// 칸 <= 주사위 바닥면
	}
	else {
		dice[3] = map[x][y];	// 주사위 바닥면 <= 칸, 칸 <= 0
		map[x][y] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	// 처음 주사위 놓기
	dice[3] = map[x][y];
	map[x][y] = 0;

	int dir;
	for (int k = 0; k < K; k++) {
		cin >> dir;

		// 방향에 따라 좌표 변경
		if (dir == 1) y = y + 1;
		else if (dir == 2) y = y - 1;
		else if (dir == 3) x = x - 1;
		else if (dir == 4) x = x + 1;

		// 범위 밖이면 변경했던 좌표값 복원하고 pass
		if (x < 0 || x >= N || y < 0 || y >= M) {	
			if (dir == 1) y = y - 1;		
			else if (dir == 2) y = y + 1;
			else if (dir == 3) x = x + 1;
			else if (dir == 4) x = x - 1;
			continue;
		}

		simulation(x, y, dir);		// 방향대로 굴리기
		cout << dice[1] << "\n";	// 윗면 출력
	}
}