#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
연속합
연속된 몇 개의 수를 선택하여 구할 수 있는 가장 큰 합?
*/

int N, num[100000], dp[100000], ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	ans = dp[0] = num[0];
	for (int i = 1; i < N; i++) {
		if (dp[i - 1] < 0) dp[i] = num[i];	// 이전까지 합이 음수라면 현재 값부터 다시 누적
		else dp[i] = dp[i - 1] + num[i];	// 음수가 아니면 이전 값 + 현재 값으로 갱신
		ans = max(ans, dp[i]);				// 연속합 최댓값
	}

	cout << ans;
}