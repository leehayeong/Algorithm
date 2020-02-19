#include <iostream> 
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

/*
촌수 계산
두 사람이 몇 촌인지 계산하여 출력
*/

int N, M, x, y;
int map[101][101];
int visited[101];

int bfs() {
	queue<pair<int, int>> q;	// 현재 사람, 촌 수 cnt pair

	// 시작 x부터, 현재 촌 수 0
	q.push(make_pair(x, 0));
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		// 도착지점인 y에 도달하면 종료
		if (cur == y) return cnt;

		// 현재 연결된 사람들 탐색
		for (int i = 1; i <= N; i++) {
			if (map[cur][i] == 0) continue;

			int next = i;

			// 방문할 수 있으면 방문
			if (visited[next] == 0) {
				q.push(make_pair(next, cnt + 1));
				visited[next] = 1;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> x >> y >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	cout << bfs();
}