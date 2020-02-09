#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
미로 탐색
(1,1)에서 (N,M)까지 최단거리
*/

int N, M, cnt;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int map[101][101];
int checked[101][101];

void bfs(int x, int y) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	checked[x][y] += map[x][y];

	// 큐에 내용물이 있는 동안, 탐색하면서 방문
	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
		
			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;

			// 방문하지 않았으면, 방문
			if (map[nx][ny] == 1 && checked[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				checked[nx][ny] = checked[tx][ty] + map[nx][ny];	// 이전까지 거리 합 + 지금 거리
			}
		}


	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 맵 생성
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			map[i][j] = s[j - 1] - '0';
		}
	}

	// 탐색 시작
	bfs(1, 1);
	
	cout << checked[N][M];
}