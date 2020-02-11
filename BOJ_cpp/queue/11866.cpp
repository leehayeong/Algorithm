#include <iostream> 
#include <queue>
using namespace std;

int N, K;
queue<int> q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
	while (q.size() != 1) {
		for (int i = 1; i < K; i++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
	q.pop();
}