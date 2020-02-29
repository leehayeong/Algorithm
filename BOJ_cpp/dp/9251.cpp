#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

/*
LCS 최장 공통 부분 수열
두 수열의 부분 수열이 되는 수열 중 가장 긴 것?

1. 첫행(0행), 첫열(0열)을 0으로 채움(전역변수로 선언함으로써 생략)
2. 두 문자열을 2중포문으로 비교하며 반복
   2-1. 같으면 왼쪽대각선위 값 + 1
   2-2. 다르면 max(왼쪽값, 위쪽값)

왼쪽 대각선위 + 1 을 하며 값이 갱신되는 때가 max값이 바뀌는 때와 같다.
즉, 공통 부분 수열의 길이가 1 늘어나는 지점이다.
*/

string s1, s2;
int dp[1001][1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s1 >> s2;

	int s1_length = s1.length(), s2_length = s2.length();
	int lcs_length = 0;

	for (int i = 1; i <= s1_length; i++) {
		for (int j = 1; j <= s2_length; j++) {
			if (s1[i - 1] == s2[j - 1]) {			
				dp[i][j] = dp[i - 1][j - 1] + 1;			// 같으면 좌대각선 위 값 + 1
				lcs_length = max(lcs_length, dp[i][j]);		// 같을때가 최댓값이 업데이트 되는 때임.
			}
			else {	
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	// 다르면 max(왼쪽값, 위쪽값)
			}
		}
	}

	cout << lcs_length;
}