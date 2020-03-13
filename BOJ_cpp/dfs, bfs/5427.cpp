#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
불
상근이가 불을 피해 탈출할 수 있는 가장 빠른 시간은?
(벽에는 불이 붙지 않는다)

불이 퍼지는 시간과, 상근이가 탈출하는 시간을 비교한다.
*/

int W, H;
char map[1000][1000];
int fvisited[1000][1000], svisited[1000][1000];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int INF = 1000000000;

void bfs(vector<pair<int, int>> v, int visited[1000][1000]) {
	queue<pair<int, int>> q;

	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		q.push(v[i]);
		visited[v[i].first][v[i].second] = 0;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

			// 벽이 아니고 방문하지 않았을 때 이동
			if (map[nx][ny] != '#' && visited[nx][ny] == -1) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int escape(vector<pair<int, int>> door) {
	int ret = INF;

	int dsize = door.size();
	for (int i = 0; i < dsize; i++) {
		int x = door[i].first;
		int y = door[i].second;

		// 상근이가 이미 탈출가능한 곳에 있으면 탈출 (가장 최소 시간임)
		if (svisited[x][y] == 0) {
			return 0;
		}

		// 상근이가 갈 수 없는 곳이면 다음으로
		else if (svisited[x][y] == -1) continue;

		// 불은 문까지 도달하지 못하고, 상근이만 도달하면 탈출 가능
		else if (fvisited[x][y] == -1 && svisited[x][y] != -1) {
			ret = min(ret, svisited[x][y]);
		}

		// 상근이의 시간이 불이 퍼지는 시간보다 작으면 탈출 가능
		else if (fvisited[x][y] > svisited[x][y]) {
			ret = min(ret, svisited[x][y]);
		}
	}

	return ret;	
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> W >> H;

		vector<pair<int, int>> fire;	// 초기 불의 위치
		vector<pair<int, int>> sg;		// 상근이 초기 위치
		vector<pair<int, int>> door;	// 나갈 수 있는 곳의 위치 (가장자리)
		for (int i = 0; i < H; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < W; j++) {
				map[i][j] = s[j];

				if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
					if (map[i][j] == '.' || map[i][j] == '@') door.push_back(make_pair(i, j));
				}

				if (map[i][j] == '*') fire.push_back(make_pair(i, j));
				if (map[i][j] == '@') sg.push_back(make_pair(i, j));
			}
		}

		// 불 확산
		memset(fvisited, -1, sizeof(fvisited));
		bfs(fire, fvisited);

		// 상근 이동
		memset(svisited, -1, sizeof(svisited));
		bfs(sg, svisited);

		// 탈출할 수 있는지 판단
		int ans = escape(door);

		if (ans == INF) cout << "IMPOSSIBLE\n";
		else cout << ans + 1 << "\n";
	}
}