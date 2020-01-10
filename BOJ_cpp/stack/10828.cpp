#include <cstdio>
#include <iostream>

using namespace std;

/*
스택 구현
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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