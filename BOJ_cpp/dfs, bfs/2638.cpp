#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
치즈
치즈가 모두 녹아 없어지는데 걸리는 시간은?
1. 치즈는 두 면 이상 접촉하면 녹는다.
2. 치즈 내부 공간은 외부 접촉면에 포함하지 않는다.

치즈 있는 부분 1, 치즈 없는 부분 0
*/

int N, M, ans, map[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = false;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			// 외부 공기면 -1로 변경
			if (!visited[nx][ny] && map[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				map[nx][ny] = -1;
			}
		}
	}
}

bool melt() {
	vector<pair<int, int>> cheese;	// 녹일 치즈를 저장하는 배열
	bool flag = false;				// 치즈 녹였으면 true로 변경

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 1) continue;

			int tx = i, ty = j;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = tx + dx[k];
				int ny = ty + dy[k];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

				if (map[nx][ny] == -1) cnt++;
			}

			// 2방향 이상 외부공기와 인접하면 녹이기 위해 배열에 push
			if (cnt >= 2) {
				cheese.push_back(make_pair(tx, ty));
			}
			
		}
	}

	// 치즈 녹이기
	int size = cheese.size();
	for (int i = 0; i < size; i++) {
		map[cheese[i].first][cheese[i].second] = 0;
		flag = true;
	}

	// 외부공간 -1에서 0으로 다시 복구
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) map[i][j] = 0;
		}
	}

	return flag;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		memset(visited, false, sizeof(visited));
		bfs(0, 0);		// 외부공기 파악
		if (!melt()) {	// 치즈 녹이기
			break;		// 녹은 치즈가 없으면 종료
		}
		ans++;
	}

	cout << ans;
}