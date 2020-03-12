#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
환승
K개의 역을 한번에 연결하는 하이퍼튜브 M개가 있다.
1번 역부터 N번 역까지 가는 데 방문하는 최소 역의 수는?

하이퍼튜브도 하나의 역으로 취급한다.
*/

int N, K, M;
vector<int> map[101001];
int dist[101001];


int bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == N) return dist[cur];

		int size = map[cur].size();
		for (int i = 0; i < size; i++) {
			int next = map[cur][i];
			
			// 아직 방문하지 않은 지점에 대해 업데이트
			if (dist[next] == 0) {
				q.push(next);
				if (next > N) dist[next] = dist[cur];	// 하이퍼튜브는 거쳐가는 역 수에 포함 X
				else dist[next] = dist[cur] + 1;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> M;

	// N개 + 1 부터 하이퍼튜브도 하나의 역으로 취급하여 연결 정보 저장
	for (int i = N + 1; i <= N + M; i++) {
		for (int k = 0; k < K; k++) {
			int n;
			cin >> n;
			map[i].push_back(n);	// 하이퍼튜브 연결
			map[n].push_back(i);
		}
	}

	cout << bfs(1);
}