#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
나이트의 이동
나이트는 몇 번 이동해서 주어진 칸으로 이동할 수 있나?
*/

int L;
int map[300][300];
bool visited[300][300];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
pair<int, int> s, e;

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(s.first, s.second), 0));
	visited[s.first][s.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= L || ny < 0 || ny >= L || visited[nx][ny]) continue;

			if (nx == e.first && ny == e.second) return cnt + 1;

			q.push(make_pair(make_pair(nx, ny), cnt + 1));
			visited[nx][ny] = true;
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> L;
		cin >> s.first >> s.second >> e.first >> e.second;
		memset(visited, false, sizeof(visited));
		cout << bfs() << "\n";
	}
}