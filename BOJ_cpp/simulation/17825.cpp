#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

/*
주사위 윷놀이
*/

typedef struct {
	int x, y;
}Point;

int ans;
int map[7][21]; bool visited[7][21];
int dice[10]; 
Point list[4]; int score[4];

// n번 말을 dice만큼 이동
Point move(int n, int dice) {
	int x = list[n].x;
	int y = list[n].y;

	int ny = y + dice;
	if (x == 1) {
		if (ny <= 20) {
			if (ny == 5) {
				x = 2; y = 1;
			}
			else if (ny == 10) {
				x = 4; y = 1;
			}
			else if (ny == 15) {
				x = 3; y = 1;
			}
			else if (ny == 20) {
				x = 6; y = 1;	
			}
			else {
				y = ny;
			}
		}
		else {
			x = 6; y = 2;		// 도착
		}
	}
	else if (x == 2 || x == 3) {
		if (ny < 5) {
			y = ny;
		}
		else if (ny == 5) {
			x = 5; y = 1;		
		}
		else {
			int nny = ny - 5 + 1;
			if (nny < 4) {
				x = 5; y = nny;
			}
			else if (nny == 4) {
				x = 6; y = 1;
			}
			else {
				x = 6; y = 2;	// 도착
			}
		}
	}
	else if (x == 4) {
		if (ny < 4) {
			y = ny;
		}
		else if (ny == 4) {
			x = 5; y = 1;		
		}
		else {
			int nny = ny - 4 + 1;
			if (nny < 4) {
				x = 5; y = nny;
			}
			else if (nny == 4) {
				x = 6; y = 1;
			}
			else {
				x = 6; y = 2;	// 도착
			}
		}
	}
	else if (x == 5) {
		if (ny < 4) {
			y = ny;
		}
		else if (ny == 4) {
			x = 6; y = 1;
		}
		else {
			x = 6; y = 2;		// 도착
		}
	}
	else if (x == 6) {
		// 무조건 도착!
		y = 2;
	} 

	return { x, y };
}

void dfs(int cnt) {
	if (cnt == 10) {
		ans = max(ans, score[0] + score[1] + score[2] + score[3]);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int cx = list[i].x;
		int cy = list[i].y;

		// 이미 도착한 말이면 다음
		if (cx == 6 && cy == 2) continue;

		// 말의 다음 위치
		Point next = move(i, dice[cnt]);
		int nx = next.x;
		int ny = next.y;

		// 가려는 곳에 말이 이미 있으면 다음 말 선택 (도착지가 아닌 경우에만)
		if (visited[nx][ny] && !(nx == 6 && ny == 2)) continue;

		// 이동
		visited[cx][cy] = false;
		list[i].x = nx;
		list[i].y = ny;
		visited[nx][ny] = true;
		score[i] += map[nx][ny];

		// 다음 말 이동하도록
		dfs(cnt + 1);

		// 복원
		visited[cx][cy] = true;
		list[i].x = cx;
		list[i].y = cy;
		visited[nx][ny] = false;
		score[i] -= map[nx][ny];
	}
}

void makeScore() {
	for (int j = 1, val = 2; j <= 20; j++, val += 2) map[1][j] = val;
	for (int j = 1, val = 10; j <= 4; j++, val += 3) map[2][j] = val;
	map[2][5] = 25;
	map[3][1] = 30;
	for (int j = 2, val = 28; j <= 5; j++, val -= 1) map[3][j] = val;
	for (int j = 1, val = 20; j <= 3; j++, val += 2) map[4][j] = val;
	map[4][4] = 25;
	for (int j = 1, val = 25; j <= 4; j++, val += 5) map[5][j] = val;
	map[6][1] = 40;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 주사위 입력
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	// 윷놀이판에 점수 할당
	makeScore();

	// 말 할당
	for (int i = 0; i < 4; i++) {
		list[i] = { 1, 0 };
	}

	// 말 조합
	dfs(0);
	cout << ans;
}