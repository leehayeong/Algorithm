#include <iostream>

using namespace std;

// 예상 대진표

int solution(int n, int a, int b)
{
	int answer = 0;

	// 두 사람의 index가 같아졌을 때 대전이 끝나고 승부가 난 것
	while (a != b) {
		// 홀수는 / 2 + 1 인덱스로, 짝수는 / 2 인덱스로 바뀜 (=반올림)
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		answer++;
	}

	return answer;
}