#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

/*
이차원 배열과 연산
*/

int N = 3, M = 3;
int r, c, k, ans;
int arr[100][100];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}

	}

	while (arr[r - 1][c - 1] != k) {
		// 종료조건
		if (ans > 100) {
			ans = -1;
			break;
		}

		// R연산
		if (N >= M) {
			vector<int> col_sizes;				// 연산 후 열 별로 크기
			int max_col = 0;					// 최대 열 크기

			for (int i = 0; i < N; i++) {
				int count[101] = { 0, };		// 수가 나온 횟수
				vector<pair<int, int>> update;	// (나온 횟수, 수)

				// 1. 나온 횟수 저장
				for (int j = 0; j < M; j++) {
					count[arr[i][j]]++;
				}

				// 2. 0을 제외한 값들 (횟수, 수)로 묶어 저장
				for (int j = 1; j <= 100; j++) {
					if (count[j] == 0) continue;
					update.push_back(make_pair(count[j], j));
				}

				// 3. 현재 열 크기 구하고, 최대 열 크기 갱신
				int cur_col = update.size() * 2;
				if (cur_col > 100) cur_col = 100;
				if (max_col < cur_col) max_col = cur_col;
				col_sizes.push_back(cur_col);

				// 5. 새 배열 저장
				sort(update.begin(), update.end());
				for (int j = 0, idx = 0; j < cur_col; j += 2, idx++) {
					arr[i][j] = update[idx].second;
					arr[i][j + 1] = update[idx].first;
				}
			}

			// 6. 열 크기 갱신
			M = max_col;

			// 7. 0채우기
			for (int i = 0; i < N; i++) {
				for (int j = col_sizes[i]; j < M; j++) {
					arr[i][j] = 0;
				}
			}
		}

		// C연산
		else {
			vector<int> row_sizes;				
			int max_row = 0;					

			for (int i = 0; i < M; i++) {
				int count[101] = { 0, };		
				vector<pair<int, int>> update;	

				for (int j = 0; j < N; j++) {
					count[arr[j][i]]++;
				}

				for (int j = 1; j <= 100; j++) {
					if (count[j] == 0) continue;
					update.push_back(make_pair(count[j], j));
				}

				int cur_row = update.size() * 2;
				if (cur_row > 100) cur_row = 100;
				if (max_row < cur_row) max_row = cur_row;
				row_sizes.push_back(cur_row);

				sort(update.begin(), update.end());
				for (int j = 0, idx = 0; j < cur_row; j += 2, idx++) {
					arr[j][i] = update[idx].second;
					arr[j + 1][i] = update[idx].first;
				}
			}

			N = max_row;

			for (int i = 0; i < M; i++) {
				for (int j = row_sizes[i]; j < N; j++) {
					arr[j][i] = 0;
				}
			}
		}

		ans++;
	}

	cout << ans;
}