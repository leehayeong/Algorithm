#include <iostream> 
#include <list>
#include <vector>
using namespace std;

class Queue {
private:
	list<int> queue;
	int num = 0;
	
public:
	void push(int x) {
		num++;
		queue.push_back(x);
	}

	void pop() {
		if (num == 0) {
			cout << -1 << "\n";
			return;
		}
		num--;
		cout << queue.front() << "\n";
		queue.pop_front();
	}

	void size() {
		cout << num << "\n";
	}

	void empty() {
		if (num == 0) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	void front() {
		if (num == 0) {
			cout << -1 << "\n";
			return;
		}
		cout << queue.front() << "\n";
	}

	void back() {
		if (num == 0) {
			cout << -1 << "\n";
			return;
		}
		cout << queue.back() << "\n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	Queue q;

	while (N--) {
		string s;
		cin >> s;

		if (s == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (s == "pop") {
			q.pop();
		}
		else if (s == "size") {
			q.size();
		}
		else if (s == "empty") {
			q.empty();
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "back") {
			q.back();
		}
	}
}