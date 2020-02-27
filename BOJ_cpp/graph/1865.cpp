#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
웜홀
출발지에서 다시 되돌아올 때, 시간이 되돌아가 있는 경우가 있나?
= 음수 싸이클이 존재하는가?
*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int N, M, W;
		int INF = 1000000000;
		vector<pair<int, int>> graph[501];
		int dist[501];

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, -c));
		}

		// 벨만포드 알고리즘
		// 1. 거리 초기화
		fill(dist, dist + N + 1, INF);
		dist[1] = 0;	// 출발지=1 (임의설정)

		// 2. 거리 갱신
		bool isCycle = false;
		for (int k = 1; k <= N; k++) {	// N번째까지 반복함으로써 음수싸이클 판단
			for (int i = 1; i <= N; i++) {
				for (int j = 0; j < graph[i].size(); j++) {
					int next = graph[i][j].first;
					int distance = graph[i][j].second;

					if (dist[i] != INF && dist[i] + distance < dist[next]) {
						dist[next] = dist[i] + distance;

						if (k == N) isCycle = true;
					}
				}
			}
		}

		if (isCycle) cout << "YES\n";
		else cout << "NO\n";
	}
}