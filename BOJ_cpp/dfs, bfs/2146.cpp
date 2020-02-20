#include <iostream> 
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/*
다리 만들기
두 섬을 잇는 가장 짧은 다리의 길이는?

1. 섬 구분
   1-1. 경계값 찾기 (섬 내에서 1->0인 부분)
   1-2. 경계값 모두 push
2. 각 섬 1칸씩 확장, cnt 세기
3. 다른 두 섬이 만났을 때 cnt 더하며 종료
*/

typedef struct {
	int x, y, cnt;
}location;

int N;
int map[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int num = 1, ans = 999;

void num_bfs(int i, int j) {
	num++;
	queue<pair<int, int>> q;

	q.push(make_pair(i, j));
	visited[i][j] = true;
	map[i][j] = num;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (map[nx][ny] == 1 && visited[nx][ny] == false) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				map[nx][ny] = num;
			}
		}
	}
}

void bfs(int num) {
	// 섬별로 거리 계산하기 위해, 같은 섬은 모두 같은 큐에 넣기
	queue<location> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == num) {
				q.push({ i, j, 0 });
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		location t = q.front();
		int tx = t.x;
		int ty = t.y;
		int cnt = t.cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			// 다른섬과 만나면 종료
			if (map[nx][ny] != 0 && map[nx][ny] != num && visited[nx][ny] == false) {
				ans = min(ans, cnt);
				return;
			}

			// 다음위치가 바다라면(0) 계속 탐색
			if (map[nx][ny] == 0 && visited[nx][ny] == false) {
				q.push({ nx, ny, cnt + 1 });
				visited[nx][ny] = true;
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 섬 구분하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 섬 구분
			if (map[i][j] == 1 && visited[i][j] == 0) {
				num_bfs(i, j);
			}
		}
	}

	// 섬별로 거리 최솟 값 계산하기
	for (int k = 2; k <= num; k++) {
		// 새로운 섬으로 바뀔 때마다 초기화 필요
		memset(visited, false, sizeof(visited));

		// k번 섬 탐색
		bfs(k);
	}

	cout << ans;
}