#include <iostream> 
#include <queue>
using namespace std;

/*
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

배열에 정수 x (x ≠ 0)를 넣는다.
배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
*/

struct compare{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, compare> q;

	while (N--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout << q.top() << "\n";
			q.pop();
		}
		else {
			q.push(x);
		}
	}
}