#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
큐빙
큐브 돌렸을 때, 맨 윗면의 상태는?
*/

int T;
char map[6][3][3];	// 면, 가로, 세로
char side[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };	// 위, 아래, 앞, 뒤, 왼, 오

void printUp() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << map[0][i][j];
		}
		cout << "\n";
	}
}

void up(int k) {
	// 2번 0행 -> 4번 0행 -> 3번 0행 -> 5번 0행
	for (int i = 0; i < k; i++) {
		int tmp[3] = { map[2][0][0], map[2][0][1], map[2][0][2] };
		for (int j = 0; j < 3; j++) map[2][0][j] = map[5][0][j];
		for (int j = 0; j < 3; j++) map[5][0][j] = map[3][0][j];
		for (int j = 0; j < 3; j++) map[3][0][j] = map[4][0][j];
		for (int j = 0; j < 3; j++) map[4][0][j] = tmp[j];
	}
}

void down(int k) {
	// 2번 2행 -> 5번 2행 -> 3번 2행 -> 4번 2행
	for (int i = 0; i < k; i++) {
		int tmp[3] = { map[2][2][0], map[2][2][1], map[2][2][2] };
		for (int j = 0; j < 3; j++) map[2][2][j] = map[4][2][j];
		for (int j = 0; j < 3; j++) map[4][2][j] = map[3][2][j];
		for (int j = 0; j < 3; j++) map[3][2][j] = map[5][2][j];
		for (int j = 0; j < 3; j++) map[5][2][j] = tmp[j];
	}
}

void left(int k) {
	// 2번 0열 -> 1번 0열 -> 3번 2열(역순) -> 0번 0열(역순)
	for (int i = 0; i < k; i++) {
		int tmp[3] = { map[2][0][0], map[2][1][0], map[2][2][0] };
		for (int j = 0; j < 3; j++) map[2][j][0] = map[0][j][0];
		for (int j = 0; j < 3; j++) map[0][j][0] = map[3][2 - j][2];
		for (int j = 0; j < 3; j++) map[3][j][2] = map[1][2 - j][0];
		for (int j = 0; j < 3; j++) map[1][j][0] = tmp[j];
	}
}

void right(int k) {
	// 2번 2열 -> 0번 2열 -> 3번 0열(역순) -> 1번 2열 (역순)
	for (int i = 0; i < k; i++) {
		int tmp[3] = { map[2][0][2], map[2][1][2], map[2][2][2] };
		for (int j = 0; j < 3; j++) map[2][j][2] = map[1][j][2];
		for (int j = 0; j < 3; j++) map[1][j][2] = map[3][2 - j][0];
		for (int j = 0; j < 3; j++) map[3][j][0] = map[0][2 - j][2];
		for (int j = 0; j < 3; j++) map[0][j][2] = tmp[j];
	}
}

void front(int k) {
	// 0번 2행(역순) -> 5번 0열 -> 1번 0행(역순) -> 4번 2열
	for (int i = 0; i < k; i++) {
		int tmp[3] = { map[0][2][0], map[0][2][1], map[0][2][2] };
		for (int j = 0; j < 3; j++) map[0][2][j] = map[4][2 - j][2];
		for (int j = 0; j < 3; j++) map[4][j][2] = map[1][0][j];
		for (int j = 0; j < 3; j++) map[1][0][j] = map[5][2 - j][0];
		for (int j = 0; j < 3; j++) map[5][j][0] = tmp[j];
	}
}

void back(int k) {
	// 0번 0행 -> 4번 0열(역순) -> 1번 2행 -> 5번 2열(역순)
	for (int i = 0; i < k; i++) {
		int tmp[3] = { map[0][0][0], map[0][0][1], map[0][0][2] };
		for (int j = 0; j < 3; j++) map[0][0][j] = map[5][j][2];
		for (int j = 0; j < 3; j++) map[5][j][2] = map[1][2][2 - j];
		for (int j = 0; j < 3; j++) map[1][2][j] = map[4][j][0];
		for (int j = 0; j < 3; j++) map[4][j][0] = tmp[2 - j];
	}
}

// side[3][3]을 map[i][j][s]면에 복사
void sideCopy(char side[3][3], int s) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[s][i][j] = side[i][j];
		}
	}
}

void rot(int side, int dir) {	
	// 해당 면 시계/반시계 회전
	char new_side[3][3];
	if (dir == 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				new_side[j][2 - i] = map[side][i][j];
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				new_side[2 - j][i] = map[side][i][j];
			}
		}
	}
	sideCopy(new_side, side);

	// 반시계방향은 시계방향을 3번 반복하는 것과 같음
	int k = 1;
	if (dir == 1) k = 3;									

	// 붙어있는 면들 회전
	if (side == 0) up(k);
	else if (side == 1) down(k);
	else if (side == 2) front(k);
	else if (side == 3) back(k);
	else if (side == 4) left(k);
	else if (side == 5) right(k);
}

void initialize() {
	for (int k = 0; k < 6; k++) {
		//char cnt = 'a';
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				map[k][i][j] = side[k];
				//map[k][i][j] = cnt;
				//cnt++;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		// 큐브 초기화
		initialize();

		// 회전 명령 n번 수행
		int n;
		cin >> n;

		while (n--) {
			string cmd;
			cin >> cmd;
			char side, dir;
			side = cmd[0]; dir = cmd[1];

			// 면, 방향 숫자 변환
			int nside, ndir;
			if (side == 'U') nside = 0;
			else if (side == 'D') nside = 1;
			else if (side == 'F') nside = 2;
			else if (side == 'B') nside = 3;
			else if (side == 'L') nside = 4;
			else if (side == 'R') nside = 5;
			if (dir == '+') ndir = 0;
			else if (dir == '-') ndir = 1;
			
			// 회전
			rot(nside, ndir);

			/*
			// 테스트출력
			cout << n << "번 명령\n";
			printMap();
			cout << "\n";
			*/
		}

		// 윗면 출력
		printUp();
	}
}

/*
void printMap() {
	for (int k = 0; k < 6; k++) {
		cout << "k=" << k << " " << trans[k] << "\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << map[k][i][j] << " ";
			}
			cout << "\n";
		}
	}
}
*/