#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
로봇 조종하기
로봇은 위쪽으로 이동 X
(0,0)에서 (N,M)까지 탐사 지역 가치 합의 최대는?

0열은 ↓
그 외 행,열 원소는 → ↓ 중 최대, ↓ ← 중 최대를 각각 구하고,
또 위 둘 중 최대를 구해 갱신한다.
*/

int N, M;
int map[1000][1000], dp[1000][1000];
int tl[1000], tr[1000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	// dp를 이용하여 탐색하면서 위치마다 최댓값 갱신
	dp[0][0] = map[0][0];
	for (int j = 1; j < M; j++) {			
		dp[0][j] = dp[0][j - 1] + map[0][j];	// 0행 갱신
	}

	for (int i = 1; i < N; i++) {				// 그 외 행, 열 비교 갱신											
		tl[0] = dp[i - 1][0] + map[i][0];
		for (int j = 1; j < M; j++) {		
			tl[j] = max(dp[i - 1][j], tl[j - 1]) + map[i][j];	// → ↓ 방향
		}

		tr[M - 1] = dp[i - 1][M - 1] + map[i][M - 1];
		for (int j = M - 2; j >= 0; j--) {	
			tr[j] = max(dp[i - 1][j], tr[j + 1]) + map[i][j];	// ↓ ← 방향
		}

		for (int j = 0; j < M; j++) {		
			dp[i][j] = max(tl[j], tr[j]);		// left방향, right방향 비교 후 최대값으로 갱신
		}
	}

	cout << dp[N - 1][M - 1];
}