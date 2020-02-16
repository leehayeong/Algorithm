#include <iostream> 
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*
외판원 순회
가장 적은 비용을 들이는 여행 계획
비용 W[i][j]. W[i][j] != W[j][i]일 수 있음, 갈 수 없으면 0
최소 비용 출력
*/

// 정점 N, 간선 M, 양 끝점 u, v
int N;
int w[10][10];
int checked[10];
int cost;
int result = 10000000;

void dfs(int start, int end, int n) {
	// 모두 방문 했는지 체크
	if (n == N - 1 && w[end][0] != 0) {
		cost += w[end][0];
		result = min(result, cost);
		cost -= w[end][0];
		return;
	}

	for (int i = 0; i < N; i++) {
		if (checked[i] == false && w[end][i] != 0) {
			cost += w[end][i];
			checked[i] = true;
			dfs(end, i, n + 1);
			cost -= w[end][i];
			checked[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}

	// 0에서 출발, 모든 경로 구하기
	checked[0] = true;
	dfs(0, 0, 0);
	checked[0] = false;

	cout << result;
}