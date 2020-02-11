#include <iostream> 
#include <list>
using namespace std;

class Dequeue {
private:
	list<int> dequeue;
	int num = 0;

public:
	void push_front(int x) {
		num++;
		dequeue.push_front(x);
	}

	void push_back(int x) {
		num++;
		dequeue.push_back(x);
	}

	void pop_front() {
		if (num == 0) {
			cout << -1 << "\n";
			return;
		}
		num--;
		cout << dequeue.front() << "\n";
		dequeue.pop_front();
	}

	void pop_back() {
		if (num == 0) {
			cout << -1 << "\n";
			return;
		}
		num--;
		cout << dequeue.back() << "\n";
		dequeue.pop_back();
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
		cout << dequeue.front() << "\n";
	}

	void back() {
		if (num == 0) {
			cout << -1 << "\n";
			return;
		}
		cout << dequeue.back() << "\n";
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	Dequeue deq;

	while (N--) {
		string s;
		cin >> s;

		if (s == "push_front") {
			int x;
			cin >> x;
			deq.push_front(x);
		}
		else if (s == "push_back") {
			int x;
			cin >> x;
			deq.push_back(x);
		}
		else if (s == "pop_front") {
			deq.pop_front();
		}
		else if (s == "pop_back") {
			deq.pop_back();
		}
		else if (s == "size") {
			deq.size();
		}
		else if (s == "empty") {
			deq.empty();
		}
		else if (s == "front") {
			deq.front();
		}
		else if (s == "back") {
			deq.back();
		}
	}
}