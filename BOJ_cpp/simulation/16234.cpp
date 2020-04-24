#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

/*
인구 이동
*/

int N, L, R, ans;
int map[50][50];
bool visited[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void printMap() {
	cout << "\nmap\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "visited\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) cout << "T\t";
			else cout << "F\n";
		}
		cout << "\n";
	}
}

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> moveList;
	int sum, cnt;

	q.push(make_pair(x, y));
	moveList.push_back(make_pair(x, y));
	visited[x][y] = true;
	sum = map[x][y];
	cnt = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])continue;

			// 인구 차 구하기
			int diff = abs(map[cx][cy] - map[nx][ny]);

			// 인구 이동을 위한 합, 국가 수 구하기
			if (L <= diff && diff <= R) {
				q.push(make_pair(nx, ny));
				moveList.push_back(make_pair(nx, ny));
				visited[nx][ny] = true;
				sum += map[nx][ny];
				cnt++;
			}
		}
	}

	// 인구이동이 없음
	if (cnt == 1) return 0;

	// 탐색 끝났으면 인구 이동
	int size = moveList.size();
	int move = sum / cnt;
	for (int i = 0; i < size; i++) {
		int tx = moveList[i].first;
		int ty = moveList[i].second;
		map[tx][ty] = move;
	}

	return 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		int cnt = 0;
		memset(visited, false, sizeof(visited));

		// BFS로 인구 이동가능한지 확인
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == false) {
					cnt += bfs(i, j);
				}
			}
		}

		printMap();

		// 인구이동이 한 번도 일어나지 않으면 종료
		if (cnt == 0) break;

		// 인구이동이 일어나면 횟수 증가
		ans++;
		cout << "**ans=" << ans << "\n";
	}

	cout << ans;
}