#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

/*
미로만들기
시작방에서 끝방으로 가기 위해 방의 개수를 바꾸는 최소 수는?
*/

int N, map[50][50];
int visited[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 0;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			
			// 이동하려는 곳이 이미 이전보다 적은 수의 방을 바꿨다면 추가로 바꿀 필요 X. 다음으로.
			if (visited[nx][ny] <= visited[tx][ty]) continue;

			// 흰 방이면 방문하고 다음 push
			if (map[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[tx][ty];
			}
			// 검은방이면 변경하는 카운트 증가시키고 push
			else if (map[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[tx][ty] + 1;
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
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	memset(visited, 100, sizeof(visited));	// max값 100
	bfs(0, 0);

	cout << visited[N - 1][N - 1];
}