#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

/*
View
왼쪽과 오른쪽 모두 2 이상의 조망권이 확보된 세대의 수
*/

int map[1000];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}

		// 현재-1, 현재-2, 현재+1, 현재+2 비교
		int ans = 0;
		for (int i = 2; i < N - 2; i++) {
			int cur = map[i];
			if (cur == 0 || cur <= map[i - 1] || cur <= map[i - 2]|| cur <= map[i + 1]|| cur <= map[i + 2]) continue;

			int vmin = 256;
			vmin = min(vmin, cur - map[i - 1]);
			vmin = min(vmin, cur - map[i - 2]);
			vmin = min(vmin, cur - map[i + 1]);
			vmin = min(vmin, cur - map[i + 2]);
			ans += vmin;
		}

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}