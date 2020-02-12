#include <iostream> 
#include <queue>
using namespace std;

/*
최대 힙
배열에 자연수 x를 넣는다.
배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, less<int>> q;

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