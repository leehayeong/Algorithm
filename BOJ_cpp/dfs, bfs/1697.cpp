#include <cstdio>
#include <iostream> 
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
수빈이 X-1, X+1, 2X 로 이동
동생을 찾는 최소 시간?
*/

int N, K;
int checked[100001];

void bfs(int start) {
	queue<int> q;

	q.push(start);
	checked[start] = 0;

	while (!q.empty()) {
		int tx = q.front();
		q.pop();

		int nx[3];
		nx[0] = tx - 1;
		nx[1] = tx + 1;
		nx[2] = 2 * tx;

		for (int i = 0; i < 3; i++) {
			// 범위 벗어나면 다음으로
			if (nx[i] < 0 || nx[i] > 100000) continue;

			// 동생에게 도착하지 않으면, 계속 탐색
			if (checked[nx[i]] == -1) {
				q.push(nx[i]);
				checked[nx[i]] = checked[tx] + 1;
			}

			// 도착했으면, 종료
			if (nx[i] == K) return;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	fill_n(checked, 100001, -1);

	// 수빈이가 동생보다 오른쪽에 있으면, -1 이동밖에 못하므로 N-K
	// 아니라면 BFS 탐색
	if (N > K) checked[K] = N - K;
	else bfs(N);

	cout << checked[K];
}