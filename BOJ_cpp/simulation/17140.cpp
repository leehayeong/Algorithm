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
			vector<int> count_size;	// 연산 후 열 별로 크기
			int max_col = 0;		// 최대 열 크기

			for (int i = 0; i < N; i++) {
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				map<int, int> count;

				// 1. 나온 횟수 저장
				for (int j = 0; j < M; j++) {
					count[arr[i][j]]++;
				}

				// 2. 현재 열 크기 구하기
				int cur_col = count.size() * 2;

				// 3. 우선순위큐에 (등장횟수, 수 크기) 오름차순이 되도록 저장
				map<int, int>::iterator it = count.begin();
				while (it != count.end()) {
					if (it->first == 0) cur_col -= 2;
					else pq.push(make_pair(it->second, it->first));
					it++;
				}
				if (cur_col > 100) cur_col = 100;

				// 4. 현재 열 크기 저장, 최대 열 크기 갱신
				count_size.push_back(cur_col);
				if (max_col < cur_col) max_col = cur_col;

				// 5. 새 배열 저장
				for (int j = 0; j < cur_col; j += 2) {
					arr[i][j] = pq.top().second;
					arr[i][j + 1] = pq.top().first;
					pq.pop();
				}
			}

			// 6. 열 크기 갱신
			M = max_col;

			// 7. 0채우기
			for (int i = 0; i < N; i++) {
				for (int j = count_size[i]; j < M; j++) {
					arr[i][j] = 0;
				}
			}
		}

		// C연산
		else {
			vector<int> count_size;	// 연산 후 행 별로 크기
			int max_row = 0;		// 최대 행 크기

			for (int i = 0; i < M; i++) {
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				map<int, int> count;

				// 1. 나온 횟수 저장
				for (int j = 0; j < N; j++) {
					count[arr[j][i]]++;
				}

				// 2. 현재 행 크기 구하기
				int cur_row = count.size() * 2;

				// 3. 우선순위큐에 (등장횟수, 수 크기) 오름차순이 되도록 저장
				map<int, int>::iterator it = count.begin();
				while (it != count.end()) {
					if (it->first == 0) cur_row -= 2;
					else pq.push(make_pair(it->second, it->first));
					it++;
				}
				if (cur_row > 100) cur_row = 100;

				// 4. 현재 행 크기 저장, 최대 행 크기 갱신
				count_size.push_back(cur_row);
				if (max_row < cur_row) max_row = cur_row;

				// 5. 새 배열 저장
				for (int j = 0; j < cur_row; j += 2) {
					arr[j][i] = pq.top().second;
					arr[j + 1][i] = pq.top().first;
					pq.pop();
				}
			}

			// 6. 행 크기 갱신
			N = max_row;

			// 7. 0채우기
			for (int i = 0; i < M; i++) {
				for (int j = count_size[i]; j < N; j++) {
					arr[j][i] = 0;
				}
			}
		}

		ans++;
	}

	cout << ans;
}