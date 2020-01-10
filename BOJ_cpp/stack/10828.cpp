#include <cstdio>
#include <iostream>

using namespace std;

/*
���� ����
push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

class Stack {
private:
	int data[100000];
	int v_top = -1;
public:
	void push(int x) {
		data[++v_top] = x;
	}

	int pop() {
		if (empty()) return -1;
		return data[v_top--];
	}

	int size() {
		return v_top + 1;
	}

	int empty() {
		if (v_top == -1)return 1;
		return 0;
	}

	int top() {
		if (empty()) return -1;
		return data[v_top];
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	Stack stack;
	int t;
	cin >> t;

	while (t--) {
		string input;
		cin >> input;
		
		if (input == "push") {
			int num;
			cin >> num;
			stack.push(num);
			continue;
		}

		if (input == "pop") {
			cout << stack.pop() << "\n";
		}

		if (input == "size") {
			cout << stack.size() << "\n";
		}

		if (input == "empty") {
			cout << stack.empty() << "\n";
		}

		if (input == "top") {
			cout << stack.top() << "\n";
		}
	}
}