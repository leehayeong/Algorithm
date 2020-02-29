#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
계단오르기
연속으로 세 계단 밟으면 안 된다. 점수의 최댓값은?
한 칸 연속, 두 칸 연속 나누어 저장
*/

int N, score[301], dp[301][3];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}

	// 첫 계단은 한 칸 연속으로만 밟을 수 있음
	dp[1][1] = score[1];
	dp[1][2] = 0;

	// 두 번째 계단을 한 칸 연속으로 밟으려면 두 번 점프로 가능
	// 두 칸 연속은 첫번째 칸 -> 두번째 칸
	dp[2][1] = score[2];
	dp[2][2] = score[1] + score[2];

	// 세 번째 계단부터 규칙 반복
	for (int i = 3; i <= N; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];	// 한 칸 연속이므로 그 전 계단은 두 칸 전이어야 함
		dp[i][2] = dp[i - 1][1] + score[i];	// 두 칸 연속이므로 그 전 계단은 한 칸 전이어야 함
	}

	cout << max(dp[N][1], dp[N][2]);
}