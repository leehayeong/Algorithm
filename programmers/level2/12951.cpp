#include <string>
#include <vector>
#include <iostream>

using namespace std;

// JadenCase 문자열 만들기
// 모든 단어의 첫 문자가 대문자, 그 외는 모두 소문자

string solution(string s) {
	string answer = "";
	int start = 0, end = 0, length = s.length();

	while (end != length) {
		end = s.find(' ', start);
		if (end == -1) end = length;

		s[start] = toupper(s[start]);
		for (int i = start + 1; i < end; i++) {
			s[i] = tolower(s[i]);
		}

		start = end + 1;
	}
	answer = s;

	return answer;
}