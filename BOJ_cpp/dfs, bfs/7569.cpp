#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
토마토가 모두 익는 최소 일수를 구하라.
상자 가로 M, 세로 N, 높이 H
정수 1 = 익은 토마토, 0 = 익지 않은 토마토, -1 = 들어있지 않은 칸
*/

int N, M, H;

// 왼쪽, 오른쪽, 뒤, 앞, 아래, 위
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
int map[101][101][101];
int checked[101][101][101];

void bfs() {
	queue<pair<pair<int, int>, int>> q;

	// 토마토가 익어있는 곳을 모두 큐에 넣는다. (동시에 익어나가게 하기 위해서)
	for (int h = 1; h <= H; h++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j][h] == 1) {
					q.push(make_pair(make_pair(i, j), h));
					checked[i][j][h] = map[i][j][h];
				}

				// 토마토가 없다면, 표시하고 다음 위치로
				else if (map[i][j][h] == -1) {
					checked[i][j][h] = -1;
					continue;
				}
			}
		}
	}

	while (!q.empty()) {
		int tx = q.front().first.first;
		int ty = q.front().first.second;
		int tz = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			int nz = tz + dz[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M || nz < 1 || nz > H) continue;

			// 토마토가 아직 익지 않았다면, 익히기 (하루지나면 익는다 = checked 배열에 1 플러스)
			if (map[nx][ny][nz] == 0 && checked[nx][ny][nz] == 0) {
				q.push(make_pair(make_pair(nx, ny), nz));
				checked[nx][ny][nz] = checked[tx][ty][tz] + 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 맵 생성
	cin >> M >> N >> H;
	for (int h = 1; h <= H; h++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j][h];
			}
		}
	}

	bfs();

	// 최소 일수 = 배열에서 최댓값을 찾는다.
	int max = 0;
	for (int h = 1; h <= H; h++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				// 최댓값이 0이면, 익지 않은 토마토가 있다는 의미이므로 -1 출력하고 종료
				if (checked[i][j][h] == 0) {
					cout << -1;
					return 0;
				}

				if (checked[i][j][h] > max) max = checked[i][j][h];
			}
		}
	}

	// 첫째날은 이미 토마토가 익어있으므로 총 걸린 수에서 첫째날을 뺀다.
	cout << max - 1;
}