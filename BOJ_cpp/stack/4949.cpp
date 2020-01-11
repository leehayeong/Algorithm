#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
() [] Â¦¸ÂÃã
*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	stack<char> s;
	string input;
	bool flag;

	while(true) {
		getline(cin, input);
		flag = true;
		while (!s.empty()) s.pop();

		if (input.length() == 1 && input[0] == '.') break;
		
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(' || input[i] == '[') {
				s.push(input[i]);
				continue;
			}

			if (input[i] == ')') {
				if (s.empty() || s.top() != '(') {
					flag = false;
					break;
				}
				else {
					s.pop();
				}
			}

			if (input[i] == ']') {
				if (s.empty() || s.top() != '[') {
					flag = false;
					break;
				}
				else {
					s.pop();
				}
			}
		}

		if (!s.empty()) flag = false;
		if (flag) cout << "yes\n";
		else cout << "no\n";
	}
}