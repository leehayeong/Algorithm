#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

/*
연구소 3
M개의 바이러스를 퍼트릴 때, 모든 빈 칸에 퍼트리는 데 걸리는 최소 시간은?
*/

int N, M, vsize, zero;
int ans = 2501;
int map[50][50], time[50][50]; 
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> virus;
bool visited[10], flag;

int bfs(vector<pair<int, int>> start) {
	queue<pair<int, int>> q;
	int size = start.size();
	int max = 0;
	int zzero = 0;

	memset(time, -1, sizeof(time));
	for (int i = 0; i < size; i++) {
		q.push(start[i]);
		time[start[i].first][start[i].second] = 0;
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] == 1) continue;

			// 빈칸
			if (map[nx][ny] == 0 || map[nx][ny] == 2) {
				if (time[nx][ny] == -1 || (time[nx][ny] != -1 && time[nx][ny] > time[cx][cy] + 1)) {
					time[nx][ny] = time[cx][cy] + 1;
					q.push(make_pair(nx, ny));

					// 빈칸이면, 최대 초 갱신
					if (map[nx][ny] == 0) {
						zzero++;
						if (time[nx][ny] > max) max = time[nx][ny];
					}
				}
			}
		}

		if (zzero == zero) break;
	}

	// 빈 칸에 퍼트린 수가, 원래 빈 칸보다 작다면 모두 퍼트리지 못했다는 의미
	if (zzero < zero) max = -1;

	return max;
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		vector<pair<int, int>> start;
		for (int i = 0; i < vsize; i++) {
			if (visited[i]) start.push_back(virus[i]);
		}

		// 빈 칸에 퍼트리는 데 최소 수 구하기
		int tmp = bfs(start);

		// 퍼트릴 수 있는 경우에만 갱신
		if (tmp != -1) {			
			ans = min(ans, tmp);
			flag = true;
		}
	}
	
	for (int i = idx; i < vsize; i++) {
		if (!visited[i]) {
			visited[i] = true;
			map[virus[i].first][virus[i].second] = -1;
			dfs(i, cnt + 1);
			visited[i] = false;
			map[virus[i].first][virus[i].second] = 2;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
			if (map[i][j] == 0) zero++;
		}
	}

	// 바이러스 조합 구하기
	vsize = virus.size();
	dfs(0, 0);

	// 퍼트릴 수 있는 조합이 하나라도 없으면 -1
	if (!flag) ans = -1;
	cout << ans;
}