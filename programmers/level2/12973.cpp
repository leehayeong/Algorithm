#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 짝지어 제거하기 (두문자씩 짝지어 제거)

int solution(string s)
{
	int answer = 0;
	int length = s.length();
	stack<char> st;

	for (int i = 0; i < length; i++) {
		// 스택이 비었거나 아직 짝이 없는 문자라면 push
		if (st.empty() || st.top() != s[i]) {
			st.push(s[i]);
		}
		// 짝이 지어진다면 스택에서 pop
		else if (st.top() == s[i]) {
			st.pop();
		}
	}

	// 스택에 남은 문자가 없으면 true (모두 짝지어짐), 있으면 false
	if (st.empty()) answer = 1;
	else answer = 0;

	return answer;
}