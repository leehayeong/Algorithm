#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 최댓값과 최솟값

string solution(string s) {
	string answer = "";
	vector<int> v;
	int start = 0, end = 0;

	// 띄어쓰기로 문자열 파싱
	while (end != -1) {
		end = s.find(' ', start);
		v.push_back(atoi(s.substr(start, end - start).c_str()));
		start = end + 1;
	}

	// 정렬
	sort(v.begin(), v.end());
	answer = to_string(v[0]) + " " + to_string(v[v.size() - 1]);

	return answer;
}