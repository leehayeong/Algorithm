#include <iostream> 
#include <queue>
using namespace std;

int N;
queue<int> q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	// 카드를 만든다.
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	// 카드의 개수가 1이 될때까지 반복한다.
	while (q.size() != 1) {
		// 맨 위 카드를 삭제한다.
		q.pop();

		// 맨 위 카드를 맨 아래로 옮긴다.
		int x = q.front();
		q.pop();
		q.push(x);
	}

	cout << q.front();
}