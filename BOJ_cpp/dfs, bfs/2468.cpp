#include <iostream> 
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
안전영역
물에 잠기지 않는 안전영역의 최대 개수?
*/

int N;
int map[100][100];
bool visited[100][100];
bool height[101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 최대 개수 반환
void bfs(int x, int y, int n) {
	queue<pair<int, int>> q;

	// 물 높이보다 높으면 잠기지 않으므로 push
	q.push(make_pair(x, y));
	visited[x][y] = true;	

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (map[nx][ny] > n && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val;
			cin >> val;
			map[i][j] = val;
			height[val] = true;
		}
	}

	// 높이별로 최대 개수 계산 후, 가장 최대값 구하기
	int v_max = 0, cnt = 0;
	for (int k = 0; k <= 100; k++) {
		// 물 높이가 0일때에도 안전영역의 개수를 세주어야 함
		if (k != 0 && !height[k]) continue;

		// 초기화
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}

		// 구하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > k && !visited[i][j]) {
					bfs(i, j, k);
					cnt++;
				}
			}
		}

		v_max = max(v_max, cnt);
	}

	cout << v_max;
}