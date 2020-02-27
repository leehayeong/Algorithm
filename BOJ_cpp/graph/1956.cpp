#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
운동
도로의 길이의 합이 가장 작은 사이클의 합은?
*/

int V, E;
int graph[401][401];
int INF = 1000000000;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			graph[i][j] = INF;	// 초기화
		}
	}

	for (int i = 1; i <= E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	// 플로이드 와샬
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= V; i++) {	
		ans = min(ans, graph[i][i]);	// 출발지로 돌아오므로 (i,i)인 값들만 비교하여 최종 최솟값 갱신
	}
	if (ans == INF) cout << -1;
	else cout << ans;
}