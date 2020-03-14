#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
게임
맵에 쓰여있는 수만큼 동전을 이동시킨다.
동전이 구멍에 빠지거나 맵 밖으로 벗어나면 종료
최대 이동 가능한 횟수는?
*/

typedef struct {
	int x, y;
	int val;	// 적혀있는 값
}Coin;

int N, M, ans;
char map[50][50];
int dp[50][50];
bool visited[50][50];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
	int val = map[x][y] - '0';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * val;
		int ny = y + dy[i] * val;

		// 범위 밖이거나 동전이 구멍에 빠지면 종료
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 'H') {
			ans = max(ans, dp[x][y] + 1);
			continue;
		}

		// 싸이클이 존재하여 무한 번 움직일 수 있다면 -1 = 이미 방문한 적이 있으면
		if (visited[nx][ny]) {
			ans = -1;
			return;
		}

		if (dp[nx][ny] < dp[x][y] + 1) {
			dp[nx][ny] = dp[x][y] + 1;
			visited[nx][ny] = true;
			dfs(nx, ny);
			visited[nx][ny] = false;
		}

		if (ans == -1) return;
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			map[i][j] = s[j];
		}
	}

	
	memset(dp, -1, sizeof(dp));
	visited[0][0] = true;
	dp[0][0] = 0;
	dfs(0, 0);

	cout << ans;

	/*
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp[i][j] << "\t";
		}
		cout << "\n";
	}*/
}

/*
BFS 싸이클 판단 안 됨
예)
3 2
12
HH
21

int bfs(int x, int y) {
	queue<Coin> q;
	q.push({ x, y, map[x][y] - '0'});
	visited[x][y] = 0;

	int ret = 0;
	while (!q.empty()) {
		Coin cur = q.front();
		int tx = cur.x;
		int ty = cur.y;
		int val = cur.val;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i] * val;	// 칸에 적힌 수만큼 이동
			int ny = ty + dy[i] * val;

			// 보드의 바깥으로 나가면 종료
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				ret = max(ret, visited[tx][ty] + 1);
				continue;
			}

			// 구멍이면 종료
			if (map[nx][ny] == 'H') {
				ret = max(ret, visited[tx][ty]);
				continue;
			}

			// 무한번 이동
			if (map[nx][ny] == map[tx][ty]) {
				return -1;
			}

			if (visited[nx][ny] == -1 || visited[nx][ny] < visited[tx][ty] + 1){
				visited[nx][ny] = visited[tx][ty] + 1;
				q.push({ nx, ny, map[nx][ny] - '0'});
			}
		}
	}

	return ret;
}
*/