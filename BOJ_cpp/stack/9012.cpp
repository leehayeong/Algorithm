#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

/*
��ȣ
¦�� �´� ���ڿ�����, �ƴ���
*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--) {
		stack<char> s;
		string input;
		bool flag = true;

		cin >> input;

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(') {
				s.push(input[i]);
			}
			else {
				if (s.empty()) {
					flag = false;
					break;
				}

				s.pop();
			}
		}

		if (!s.empty()) flag = false;

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}