#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
퇴사
백준이가 퇴사할 때까지 얻을 수 있는 최대 수익은?
*/

int N;
int time[16], pay[16];
int dp[17];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> pay[i];
	}

	for (int i = 1; i <= N + 1; i++) {
		int finish = i + time[i];

		if (finish <= N + 1) {
			dp[finish] = max(dp[finish], dp[i] + pay[i]);
		}

		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << dp[N + 1];
}