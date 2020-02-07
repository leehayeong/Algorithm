#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
유기농배추
테스트케이스 T, 배추밭 가로 M, 배추밭 세로 N, 배추개수 K, 배추위치 X,Y
필요한 최소 지렁이 수
*/

int T, M, N, K, X, Y, cnt;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int map[50][50];
bool checked[50][50];

// dfs 탐색
void dfs(int x, int y) {
	if (checked[x][y]) return;

	checked[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		// 배추가 있고, 방문하지 않았다면 더 탐색
		if (map[nx][ny] == 1 && !checked[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> M >> N >> K;

		// 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = 0;
				checked[i][j] = false;
			}
		}
		cnt = 0;

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		// 첫 배추 부터 탐색
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && !checked[i][j]) {
					dfs(i, j);

					// 모든 탐색이 끝나면 배추 한 묶음 끝
					cnt++;
				}
			}
		}

		cout << cnt << "\n";


	}
}