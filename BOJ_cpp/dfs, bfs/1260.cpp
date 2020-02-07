#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
DFS로 탐색한 결과와 BFS로 탐색한 결과 출력
정점의 개수 N, 간선 개수 M, 정점 번호 V
*/

int N, M, V;

// 연결그래프
vector<int> graph[1001];
bool checked[1001];

void dfs(int start) {
	if (checked[start]) return;

	checked[start] = true;
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!checked[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;

	q.push(start);
	checked[start] = true;

	while (!q.empty()) {
		int val = q.front();
		q.pop();
		cout << val << " ";

		for (int i = 0; i < graph[val].size(); i++) {
			int out = graph[val][i];
			if (!checked[out]) {
				q.push(out);
				checked[out] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 간선 sort
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	// DFS
	dfs(V);

	cout << "\n";
	fill_n(checked, N + 1, false);

	// BFS
	bfs(V);
}