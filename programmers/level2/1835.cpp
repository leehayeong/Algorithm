#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
단체사진 찍기
A~C=4 (A는C와 간격 4를 원한다). 총 8명 = 줄세우기 가짓 수 8!
*/

bool isPossible(string s, int n, vector<string> data) {
	int length = s.length();

	for (int i = 0; i < n; i++) {
		char a = data[i][0];
		char b = data[i][2];
		char cmd = data[i][3];  // = < > 
		int num = data[i][4] - '0';

		// 두 캐릭터 거리가 몇 칸인지 계산
		int aidx, bidx, dist;
		for (int k = 0; k < length; k++) {
			if (s[k] == a) aidx = k;
			if (s[k] == b) bidx = k;
		}
		dist = abs(aidx - bidx) - 1;  // 떨어져있는 칸 수이므로 - 1 해야 함

		// 조건에 맞지 않으면 종료
		if ((cmd == '=' && dist != num) || (cmd == '<' && dist >= num) || (cmd == '>' && dist <= num)) return false;
	}

	return true;
}

int solution(int n, vector<string> data) {
	int answer = 0;

	// 모든 조합을 구하고 조건을 만족하는지 확인 
	string list = "ACFJMNRT";
	sort(list.begin(), list.end());     // next_permutation을 쓰기 위해선 정렬 필요

	do {
		// 조건을 만족하는 배열이면 가짓수 + 1
		if (isPossible(list, n, data)) {
			answer++;
		}
	} while (next_permutation(list.begin(), list.end()));

	return answer;
}