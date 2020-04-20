#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[32][11];	// 마지막 행은 i번째가 어디에 도착하는지 저장
int N, M, H;		// 세로선, 가로선, 가로선을 놓을 수 있는 위치
vector<pair<int, int>> list;
int answer = 4;

void move(int start, int row, int col) {
	// 도착
	if (row == H + 1) {
		map[row][start] = col;
		return;
	}

	if (map[row][col] == 1) {			// 오른쪽 사다리 + 아래 이동
		move(start, row + 1, col + 1);
	}
	else if (map[row][col] == 2) {		// 왼쪽 사다리 + 아래 이동
		move(start, row + 1, col - 1);
	}
	else if (map[row][col] == 0) {		// 아래 이동
		move(start, row + 1, col);
	}
}

bool check() {
	bool flag = true;

	// 1번부터 N번까지 타고 내려가기
	for (int i = 1; i <= N; i++) {
		move(i, 1, i);

		// i번째와 다르면 바로 멈춤
		if (map[H + 1][i] != i) {
			flag = false;
			break;
		}
	}

	return flag;
}

void dfs(int row, int col, int cnt, int max_size) {
	// 최고 사다리 개수 초과하면 종료
	if (cnt > max_size) return;

	// 사다리 타고, 최솟값 갱신
	if (check()) {
		answer = min(answer, cnt);
		return;
	}

	// 사다리 추가
	for (int i = row; i <= H; i++) {
		for (int j = col; j <= N - 1; j++) {
			if (map[i][j] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;
				map[i][j + 1] = 2;
				dfs(i, j + 2, cnt + 1, max_size);
				map[i][j] = 0;
				map[i][j + 1] = 0;
			}
		}
		col = 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> H;
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;		// b번-b+1번 a위치에서 연결
		map[a][b] = 1;		// 오른쪽 방향으로 가는 사다리
		map[a][b + 1] = 2;	// 왼쪽 방향으로 가는 사다리
	}

	// 0개~3개까지 모든 사다리 조합 구함
	for (int i = 0; i <= 3; i++) {
		dfs(0, 0, 0, i);
	}

	if (answer == 4) answer = -1;
	cout << answer;
}