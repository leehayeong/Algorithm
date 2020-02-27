#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
타임머신
음수 가중치가 포함된 문제는 벨만포드로.
*/

int N, M;
int INF = 1000000000;
vector<pair<int, int>> graph[501];
int dist[501];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	// 거리 무한대로 초기화
	fill(dist, dist + N + 1, INF);
	dist[1] = 0;

	// 벨만포드 알고리즘
	bool minusCycle = false;
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j].first;
				int distance = graph[i][j].second;
				if (dist[i] != INF && dist[i] + distance < dist[next]) {
					dist[next] = dist[i] + distance;

					// i가 N인데도 값이 갱신되면, 음의 싸이클이 존재한다.
					if (k == N) minusCycle = true;
				}
			}
		}
	}

	if (!minusCycle) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
	else {
		cout << "-1";
	}
}