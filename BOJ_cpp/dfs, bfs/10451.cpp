#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

/*
순열사이클
*/

int N, cnt;
int num[1001];
bool visited[1001];

void bfs(int start) {
	queue<int> q;

	q.push(num[start]);
	visited[start] = true;

	while (!q.empty()) {
		int nx = q.front();
		q.pop();

		if (num[nx] == start) {
			cnt++;
			visited[nx] = true;
			return;
		}

		if (visited[nx] == false) {
			q.push(num[nx]);
			visited[nx] = true;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		fill_n(num, N + 1, 0);
		fill_n(visited, N + 1, false);
		cnt = 0;

		for (int i = 1; i <= N; i++) {
			cin >> num[i];
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i] == false) {
				bfs(i);
			}
		}

		cout << cnt << "\n";
	}
}