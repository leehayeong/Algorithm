#include <iostream> 
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

/*
영역 구하기
사각형에 의해 분리된 영역의 개수는?
*/

int M, N, K;
int map[100][100];
bool visited[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<int> ans;

void bfs(int x, int y) {
	queue<pair<int, int>> q;

	// 영역의 넓이 계산. 한칸의 넓이 = 1
	q.push(make_pair(x, y));
	visited[x][y] = true;
	int cnt = 1;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

			if (map[nx][ny] == 0 && visited[nx][ny] == false) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}

	ans.push_back(cnt);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> K;
	for (int k = 0; k < K; k++) {
		int ldx, ldy, rux, ruy;
		cin >> ldx >> ldy >> rux >> ruy;
		for (int i = ldy; i < ruy; i++) {
			for (int j = ldx; j < rux; j++) {
				map[i][j] = 1;
			}
		}
	}

	// 사각형이 없는 영역이고, 이미 영역에 포함되지 않은 부분 탐색
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j] == false) {
				bfs(i, j);
			}
		}
	}

	// 오름차순 정렬 후, 출력
	sort(ans.begin(), ans.end());
	int size = ans.size();
	cout << size << "\n";
	for (int i = 0; i < size; i++) {
		cout << ans[i] << " ";
	}
}