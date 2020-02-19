#include <iostream> 
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

/*
케빈 베이컨의 6단계 법칙
케빈 베이컨 수 = 몇 단계를 거쳐 사람과 연결되는지 횟수
케빈 베이컨의 수가 가장 적은 사람은?
*/

int N, M;
int map[101][101];
int counts[101][102];	// x는 y까지 몇 단계를 거쳐 도달하는지 저장
bool visited[101];		// 방문체크 배열, 매 단계마다 초기화 필요

void bfs(int x) {
	queue<pair<int, int>> q;	// 현재 사람, cnt pair

	q.push(make_pair(x, 0));
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (i == cur) continue;
			int next = i;

			// 연결되어있고, 방문하지 않았으면 push
			if (map[cur][next] == 1 && visited[next] == false) {
				q.push(make_pair(next, cnt + 1));
				visited[next] = true;
				counts[x][next] = cnt + 1;
			}
		}
	}

	// 총 합 계산
	for (int i = 1; i <= N; i++) {
		counts[x][N + 1] += counts[x][i];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	// 1번부터 N번까지 각각 탐색. 초기화 후, i의 케빈 베이컨 수 계산
	for (int i = 1; i <= N; i++) {
		fill_n(visited, N + 1, false);
		bfs(i);
	}

	// min 값 찾기
	int ans = 1;
	int vmin = counts[1][N + 1];
	for (int i = 2; i <= N; i++) {
		int cur = counts[i][N + 1];
		if (vmin > cur) {
			vmin = cur;
			ans = i;
		}
		else if (vmin == cur) {
			ans = min(ans, i);
		}
	}

	cout << ans;
}