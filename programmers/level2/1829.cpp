#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

// 카카오프렌즈 컬러링북 
// 영역의 수 = bfs 수행 횟수 & 최대 영역의 크기 = 수행 시 최대 cnt 값

int visited[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int x, int y, int m, int n, vector<vector<int>> picture) {
	int cnt = 1;				// 탐색한 영역 수
	queue<pair<int, int>> q;	// 좌표
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;

			// 같은 색일때에만 
			if (picture[cx][cy] == picture[nx][ny]) {
				cnt++;
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 아직 확인하지 않은 영역에 대해서만 bfs 수행
			if (picture[i][j] != 0 && !visited[i][j]) {
				int ret = bfs(i, j, m, n, picture);
				max_size_of_one_area = max(max_size_of_one_area, ret);
				number_of_area++;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

/*
int main() {
	vector<vector<int>> picture;

	for (int i = 0; i < 6; i++) {
		vector<int> list;
		for (int j = 0; j < 4; j++) {
			int x;
			cin >> x;
			list.push_back(x);
		}
		picture.push_back(list);
	}

	solution(6, 4, picture);
}
*/