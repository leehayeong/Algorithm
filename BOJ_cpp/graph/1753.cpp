#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
최단경로
주어진 시작점에서 다른 모든 정점으로의 최단 경로 = 다익스트라
*/

int V, E, S;
vector <pair<int, int>> graph[20001];
int dist[20001];	// 거리 저장
int INF = 1000000000;

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;	// 정점
		int distance = -pq.top().first;	// 가중치
		pq.pop();

		if (dist[cur] < distance) continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDistance = distance + graph[cur][i].second;

			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E >> S;

	for (int i = 1; i <= E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dijkstra(S);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
			continue;
		}
		cout << dist[i] << "\n";
	}
}