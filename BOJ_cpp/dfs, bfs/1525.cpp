#include <iostream> 
#include <queue>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

/*
퍼즐
1 2 3
4 5 6
7 8
배열을 만드는 최소 swap 횟수?

input을 int 형태로 취급하여 풀이하며 0은 9로 치환한다.
배열의 index로 사용해야 하는데, 0이 맨 앞에 올 경우엔 사라지기 때문이다.

즉, 123456780 을 123456789 int 형태로 변환하여 최종 도달해야할 값으로 보고 풀이한다.
int로 들어온 값을 string으로 변환하여 '9'가 위치한 index를 찾는다. (index 찾기엔 string이 편하기 때문)
index를 행렬(x, y)형태로 표현하는 방법과, 행렬 (x,y)형태를 다시 string의 index로 표햔하는 방법을 찾는 것이 중요하다.

x = index / 3, y = index % 3, index = x * 3 + y

swap 횟수는 매 숫자마자 이전 swap 횟수의 + 1을 하여 갱신해주는 것으로 한다.
123456780 형태가 되었을 때 swap 횟수를 리턴하며 종료한다. (BFS로 최소횟수 구하기)
*/

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
map<int, int> visited;

int bfs(int input) {
	queue<int> q;

	// 처음 입력값, swap 횟수는 0번
	q.push(input);
	visited[input] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 123456789 형태가 만들어지면 종료
		if (cur == 123456789) return visited[cur];

		// 0 위치 찾기
		string tmp = to_string(cur);
		int index = tmp.find('9');

		// 해당하는 좌표 찾기
		int x = index / 3;
		int y = index % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			// (nx, ny) 를 index 로 다시 변환하여 index 로 일차원 배열 요소들을 swap
			int nindex = nx * 3 + ny;

			// swap
			string ns = tmp;
			swap(ns[index], ns[nindex]);

			int next = atoi(ns.c_str());

			// 같지 않으면 push 
			if (visited[next] == 0) {
				q.push(next);
				visited[next] = visited[cur] + 1;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t, input = 0;
	for (int i = 0; i < 9; i++) {
		cin >> t;
		if (t == 0) t = 9;	// 0을 9로 변환 (0은 맨 앞에 나올 경우 사라지기 때문)
		input = input * 10 + t;
	}

	cout << bfs(input);
}