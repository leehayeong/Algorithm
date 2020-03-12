#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
집 구하기
맥세권 + 스세권 = 합이 최소인 정점은?
*/

int V, E, u, v, w;	// 정점, 도로, 정점u, v, 가중치w
int M, m, S, s;		// 맥도날드 수, 조건, 스타벅스 수, 조건
vector<pair<int, int>> map[10001];
vector<int> mac, star;
int mdist[10001], sdist[10001];
int INF = 1000000000;

void dijkstra(vector<int> list, int dist[10001]) {
	priority_queue<pair<int, int>> pq;	// 거리 음수화, 시작점부터 가게될 정점

	int lsize = list.size();
	for (int i = 0; i < lsize; i++) {
		pq.push(make_pair(0, list[i]));	// 첫 거리 0, 맥도날드 하나가 시작점
		dist[list[i]] = 0;
	}

	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (dist[cur] < distance) continue;

		int msize = map[cur].size();
		for (int i = 0; i < msize; i++) {
			int next = map[cur][i].first;			// 다음 지점
			int next_distance = map[cur][i].second;	// 다음 지점까지 거리
		
			if (distance + next_distance < dist[next]) {	// 현재까지 거리 + 다음까지 거리가 이미 계산된 다음 까지 거리보다 작다면 여기로 이동해야 함
				pq.push(make_pair(-(distance + next_distance), next));
				dist[next] = distance + next_distance;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		map[u].push_back(make_pair(v, w));	// u에서 v까지 w만큼 가중치
		map[v].push_back(make_pair(u, w));
	}

	cin >> M >> m;	// 맥도날드 수, 맥세권 조건, 정점 번호
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		mac.push_back(n);
	}

	cin >> S >> s;	// 스타벅스 수, 스타벅스 조건, 정점 번호
	for (int i = 0; i < S; i++) {
		int n;
		cin >> n;
		star.push_back(n);
	}

	// 맥도날드 다익스트라
	fill(mdist, mdist + 10000, INF);
	dijkstra(mac, mdist);

	// 스타벅스 다익스트라
	fill(sdist, sdist + 10000, INF);
	dijkstra(star, sdist);

	// 맥세권 && 스세권 && 맥세권 + 스세권 최소
	int ans = INF;
	for (int i = 1; i <= V; i++) {
		if (mdist[i] == 0 || sdist[i] == 0) continue;
		if (mdist[i] <= m && sdist[i] <= s) {
			ans = min(ans, mdist[i] + sdist[i]);
		}
	}

	if (ans != INF) cout << ans;
	else cout << -1;
}