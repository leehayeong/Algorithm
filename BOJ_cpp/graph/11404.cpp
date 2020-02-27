#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
플로이드
도시 A에서 B로 가는 데 필요한 비용의 최솟값?
*/

int N, M;
int dist[101][101];
int INF = 1000000000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	
	// 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c < dist[a][b]) {
			dist[a][b] = c;
		}
	}

	// k = 거쳐가는 노드, i = 출발, j = 도착
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// 결과
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || dist[i][j] == INF) cout << "0 ";	// 출발지와 도착지가 같을 수는 없다 (문제 조건)
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}