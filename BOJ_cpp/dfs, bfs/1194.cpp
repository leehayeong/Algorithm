#include <iostream> 
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

/*
달이 차오른다, 가자.
민식이가 미로를 탈출하는 데 걸리는 이동횟수의 최솟값
소문자 열되로 대문자 문을 열 수 있다.
열쇠를 2진수로 표현하고 비트 연산을 통해 열쇠 소유 여부를 저장해야한다.
*/

typedef struct {
	int x, y, cnt;
	int key;	// 열쇠 소유 여부를 2진수로 표현한다. 
}Point;

int N, M;
char map[50][50];
bool visited[50][50][64];	// 모든 열쇠를 다 가진 경우가 111111이므로 10진수로 표현하면 64
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
Point s, e;	// 시작점, 끝점

int bfs(Point start) {
	queue<Point> q;
	q.push(start);
	visited[start.x][start.y][start.key] = true;	// 시작할 땐 가지고 있는 열쇠 없음

	while (!q.empty()) {
		Point cur = q.front();
		int x = cur.x;
		int y = cur.y;
		int cnt = cur.cnt;
		int key = cur.key;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (visited[nx][ny][key] == false) {
				// 1. 도착지면 종료
				if (map[nx][ny] == '1') return cnt + 1;

				// 2. 벽 지나갈 수 없음
				else if (map[nx][ny] == '#') continue;

				// 3. 빈공간이면 지나감
				else if (map[nx][ny] == '.') {
					q.push({ nx, ny, cnt + 1, key });
					visited[nx][ny][key] = true;
				}

				// 4. 열쇠 획득
				else if ('a' <= map[nx][ny] && map[nx][ny] <= 'f') {
					int get = 1 << (map[nx][ny] - 'a');		// 현재 얻은 키를 비트마스크로 표현하고
					int nkey = key | get;					// 이전 키와 OR 연산하여 얻은 키를 추가하여 키 갱신
					q.push({ nx, ny, cnt + 1, nkey });
					visited[nx][ny][nkey] = true;
				}

				// 5. 문 열기
				else if ('A' <= map[nx][ny] && map[nx][ny] <= 'F') {
					int door = 1 << (map[nx][ny] - 'A');	// 현재 만난 문 표현
					int isOpen = key & door;				// 가지고 있는 키와 문을 AND 연산하여 열 수 있는지 확인
					if (isOpen != door) continue;			// & 연산 결과가 문 자기 자신이 아니라면 열 수 없음
					q.push({ nx, ny, cnt + 1, key });
					visited[nx][ny][key] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
			if (map[i][j] == '0') {
				s = { i, j, 0, 0 };
				map[i][j] = '.';
			}
			else if (map[i][j] == '1') {
				e = { i, j, 0, 0 };
			}
		}
	}

	cout << bfs(s);
}