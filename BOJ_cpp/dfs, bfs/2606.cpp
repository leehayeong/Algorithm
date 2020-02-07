#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
바이러스
컴퓨터의 수 N, 간선 수 M
네트워크를 통해 감염되는 컴퓨터의 수는?

1. BFS 풀이
2. DFS 풀이
*/

int N, M;
vector<int> graph[101];
bool checked[101];
int cnt;

// 1. BFS 풀이
void bfs(int start) {
	queue<int> q;
	q.push(start);
	checked[start] = true;

	while (!q.empty()) {
		int val = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < graph[val].size(); i++) {
			int out = graph[val][i];
			if (!checked[out]) {
				q.push(out);
				checked[out] = true;
			}
		}
	}
}


// 2. DFS 풀이
void dfs(int start) {
	if (checked[start]) return;

	checked[start] = true;
	cnt++;

	for (int i = 0; i < graph[start].size(); i++) {
		int out = graph[start][i];
		if (!checked[out]) {
			dfs(out);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	// 그래프 생성
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 탐색
	//bfs(1);

	dfs(1);

	// 1번 컴퓨터는 제외해야하므로 -1
	cout << cnt - 1;
}