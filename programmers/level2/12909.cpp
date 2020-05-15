#include<string>
#include <iostream>
#include <stack>

using namespace std;

// 올바른 괄호

bool solution(string s)
{
	bool answer = true;
	int length = s.length();
	stack<char> st;

	for (int i = 0; i < length; i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (st.empty()) {
				answer = false;
				break;
			}
			st.pop();
		}
	}

	if (!st.empty()) answer = false;

	return answer;
}