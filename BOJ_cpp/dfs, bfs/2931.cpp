#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
가스관
M부터 시작해서 끊기는 곳 찾고, 사방탐색하며 연결 계산
*/

typedef struct {
	int x, y;
	char block;
}Block;

int R, C;
char map[25][25];
bool visited[25][25];
int dx[4] = { 0, 0, -1, 1 };	// 왼, 오, 위, 아래
int dy[4] = { -1, 1, 0, 0 };

bool isPossible(int x, int y) {
	if (x < 0 || x >= R || y < 0 || y >= C) return false;
	return true;
}

pair<int, int> findDir(int x, int y, int dir1, int dir2) {
	pair<int, int> next;

	// 범위 내이고 방문하지 않았으면 그 방향으로 설정, 아니면 반대 방향으로
	if (isPossible(x + dx[dir1], y + dy[dir1]) && !visited[x + dx[dir1]][y + dy[dir1]]) {	
		next.first = x + dx[dir1], next.second = y + dy[dir1];
	}
	else {
		next.first = x + dx[dir2], next.second = y + dy[dir2];
	}

	return next;
}

pair<int, int> bfs(int x, int y, char block) {
	queue<Block> q;
	q.push({ x, y, block });
	visited[x][y] = true;

	while (!q.empty()) {
		int tx = q.front().x;
		int ty = q.front().y;
		char tb = q.front().block;
		q.pop();

		// 4방향 탐색이 필요한 블럭
		if (tb == '+') {	// 왼,오,위,아래(0,1,2,3)
			for (int i = 0; i < 4; i++) {
				int nx = tx + dx[i];
				int ny = ty + dy[i];

				if (!isPossible(nx, ny)) continue;

				if (!visited[nx][ny]) {
					if (map[nx][ny] != '.') {		// 방향 파이프가 존재하면 push
						q.push({ nx, ny, map[nx][ny] });
						visited[nx][ny] = true;
					}
					else {							// '.' 이 나올 때로, 파이프가 끊겨있으면 끊긴 지점 저장하고 종료
						return make_pair(nx, ny);	// 끊긴 지점 return
					}
				}
			}
			continue;
		}

		// 2방향 탐색이 필요한 블럭
		pair<int, int> next;
		if (tb == '|') {		// 위,아래(2,3)
			next = findDir(tx, ty, 2, 3);
		}
		else if (tb == '-') {	// 왼,오(0,1)
			next = findDir(tx, ty, 0, 1);
		}
		else if (tb == '1') {	// 오,아래(1,3)
			next = findDir(tx, ty, 1, 3);
		}
		else if (tb == '2') {	// 오,위(1,2)
			next = findDir(tx, ty, 1, 2);
		}
		else if (tb == '3') {	// 왼,위(0,2)
			next = findDir(tx, ty, 0, 2);
		}
		else if (tb == '4') {	// 왼,아래(0,3)
			next = findDir(tx, ty, 0, 3);
		}

		int nx = next.first;
		int ny = next.second;
		
		if (!visited[nx][ny]) {
			if (map[nx][ny] != '.') {		// 방향파이프 존재하면 push
				q.push({ nx, ny, map[nx][ny] });
				visited[nx][ny] = true;
			}
			else {		
				return make_pair(nx, ny);	// 파이프 끊겨있으면 끊긴지점 return하고 종료
			}
		}
	}

	return make_pair(x, y);	// 무의미
}

char findBlock(int x, int y) {
	vector<int> dir;

	// 끊긴 지점을 기준으로 4방향 탐색
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (!isPossible(nx, ny)) continue;

		int nb = map[nx][ny];
		if (i == 0) {		// 왼쪽방향으로 가니까 오른쪽 뚫린 파이프가 필요
			if (nb == '-' || nb == '+' || nb == '1' || nb == '2') {
				dir.push_back(i);
			}
		}
		else if (i == 1) {	// 왼쪽 뚫린 파이프
			if (nb == '-' || nb == '+' || nb == '3' || nb == '4') {
				dir.push_back(i);
			}
		}
		else if (i == 2) {	// 아래쪽 뚫린 파이프
			if (nb == '|' || nb == '+' || nb == '1' || nb == '4') {
				dir.push_back(i);
			}
		}
		else if (i == 3) {	// 위쪽 뚫린 파이프
			if (nb == '|' || nb == '+' || nb == '2' || nb == '3') {
				dir.push_back(i);
			}
		}
	}

	if (dir.size() == 4) return '+';
	else if (dir[0] == 2 && dir[1] == 3) return '|';
	else if (dir[0] == 0 && dir[1] == 1) return '-';
	else if (dir[0] == 1 && dir[1] == 3) return '1';
	else if (dir[0] == 1 && dir[1] == 2) return '2';
	else if (dir[0] == 0 && dir[1] == 2) return '3';
	else if (dir[0] == 0 && dir[1] == 3) return '4';
	else return '?';	// 무의미
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;

	// 입력
	pair<int, int> m, z;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'M') m = make_pair(i, j);
			else if (map[i][j] == 'Z') z = make_pair(i, j);
		}
	}

	// 탐색 시작
	int x = m.first;
	int y = m.second;
	visited[x][y] = true;
	pair<int, int> point;	// 끊긴 지점 저장할 곳
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isPossible(nx, ny) && map[nx][ny] != '.') {
			point = bfs(nx, ny, map[nx][ny]);
		}
	}

	int px = point.first;
	int py = point.second;
	char block = findBlock(px, py);	// 끊긴 지점에 들어올 블록 찾기

	cout << px + 1 << " " << py + 1 << " " << block << "\n";
}