#include <iostream> 
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
연결 요소의 개수
그래프가 주어졌을 때, 연결 요소의 개수를 구하라.
*/

// 정점 N, 간선 M, 양 끝점 u, v
int N, M, u, v, cnt;
vector<int> graph[1001];
bool visited[1001];

void bfs(int start) {
	queue<int> q;

	for (int i = 0; i < graph[start].size(); i++) {
		q.push(graph[start][i]);
		visited[graph[start][i]] = true;
	}

	while (!q.empty()) {
		int tx = q.front();
		q.pop();

		for (int i = 0; i < graph[tx].size(); i++) {
			int nx = graph[tx][i];

			if (nx == start) {
				break;
			}

			if (!visited[nx]) {
				q.push(nx);
				visited[nx] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (!visited[i]) {
				visited[i] = true;
				if (!visited[graph[i][j]]) { 
					bfs(i); 
					cnt++;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt++;
		}
	}

	cout << cnt;
}