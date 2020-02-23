#include <iostream> 
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

/*
성곽
방의 개수, 가장 넓은 방의 넓이, 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
10진수->2진수, 비트연산 & 으로 벽이 있는지 없는지 확인
*/

int N, M, cnt, area, max_area;
int map[50][50], areas[2500];
bool visited[50][50];
int dx[4] = { 0, -1, 0, 1 };	// 서 북 동 남 순서
int dy[4] = { -1, 0, 1, 0 };

int bfs(int x, int y, int num) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	visited[x][y] = true;

	int ret = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
 		int flag = map[cx][cy];
		map[cx][cy] = num;		// map은 방 번호로 변경
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			// 범위 검사.
			if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[nx][ny] == true) continue;

			// 벽 검사. 비트 연산 결과가 0이면, 해당 비트가 0으로 벽이 없다는 뜻. 갈수 있음.
			int mask = pow(2, i);
			if ((flag & mask) == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				ret++;
			}
		}
	}

	areas[num] = ret;
	return ret;
}

int find_max_area(int x, int y) {
	queue<pair<int, int>> q;
	
	q.push(make_pair(x, y));
	visited[x][y] = true;

	int ret = 0;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[nx][ny] == true) continue;

			// 이웃한 두 방이 서로 다른 방이면 넓이 합하고, 최댓값 저장
			if (map[cx][cy] != map[nx][ny]) {
				ret = areas[map[cx][cy]] + areas[map[nx][ny]];
				return ret;
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 방 번호 붙여 탐색
	int num = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				// bfs 한 번 = 방 한 개, max 넓이 업데이트, 방 개수 ++
				area = max(area, bfs(i, j, num));	
				cnt++;
				num++;
			}
		}
	}

	// 방 최대 넓이 찾기. 이웃한 서로 다른 두 방 넓이 합쳐서 비교
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				max_area = max(max_area, find_max_area(i, j));
			}
		}
	}

	cout << cnt << "\n" << area << "\n" << max_area;
}