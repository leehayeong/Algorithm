#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

/*
아기 상어
*/

typedef struct {
	int x, y;
}Shark;

int N, ans;
int map[20][20];
bool visited[20][20], eating;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int ssize = 2, eat = 0;

Shark bfs(Shark start) {
	queue<pair<int, Shark>> q;	// 이동한 거리, 좌표
	q.push(make_pair(0, start));
	visited[start.x][start.y] = true;
	eating = false;

	vector<pair<int, int>> candi;
	int sec = 0;

	while (!q.empty()) {
		int dist = q.front().first;
		int cx = q.front().second.x;
		int cy = q.front().second.y;
		q.pop();

		// 먹을 수 있는 물고기보다 더 멀어질 때 BFS 탐색 종료
		if (eating == true && dist == sec) break;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;

			// 나보다 큰 물고기 = 지나갈 수 X
			if (map[nx][ny] > ssize) continue;

			// 같은 크기의 물고기 = 지나가기만 ok
			if (map[nx][ny] == ssize || map[nx][ny] == 0) {
				Shark next = { nx, ny };
				q.push(make_pair(dist + 1, next));
				visited[nx][ny] = true;
			}

			// 작은 크기의 물고기 = 먹을 후보 물고기에 추가하고, 걸린 거리만큼 시간 갱신
			else {
				candi.push_back(make_pair(nx, ny));
				visited[nx][ny] = true;
				sec = dist + 1;
				eating = true;
			}
		}
	}

	// 먹을 수 있는 물고기가 없으면 종료
	if (sec == 0) return start;

	// 가장 가까운 물고기 먹기
	sort(candi.begin(), candi.end());
	int nx = candi[0].first;
	int ny = candi[0].second;
	map[nx][ny] = 0;
	eat++;

	// 몸 크기만큼 먹으면 사이즈 증가
	if (eat == ssize) {
		ssize++;
		eat = 0;
	}

	// 걸린 시간 더하고, 먹은 곳의 좌표 반환
	ans += sec;
	return { nx, ny };
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	Shark start;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start = { i, j };
				map[i][j] = 0;
			}
		}
	}

	// 출발
	while (1) {
		Shark ret = bfs(start);

		// 더이상 먹을 물고기가 없으면 종료
		if (eating == false) break;

		// 물고기 먹은 지점부터 다시 이동 시작하도록
		start = ret;
		memset(visited, false, sizeof(visited));
	}

	cout << ans;
}