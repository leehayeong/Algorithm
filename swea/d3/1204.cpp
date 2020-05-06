#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

/*
최빈수 구하기
*/

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
	cin >> T;
	while (T--) {
		cin >> test_case;

		int cnt[101] = { 0, };
		int maxCnt = 0, maxScore = 0;

		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;

			// 점수 횟수 기록
			cnt[score]++;

			// 최빈값 찾기
			if (maxCnt < cnt[score]) {
				maxCnt = cnt[score];
				maxScore = score;
			}
			else if (maxCnt == cnt[score] && maxScore < score) {
				maxScore = score;
			}
		}

		cout << "#" << test_case << " " << maxScore << "\n";
	}

	return 0;
}