#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

// 최솟값 만들기

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	int size = A.size();

	// 정렬후 A에서 최소, B에서 최대 곱하기
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < size; i++) {
		answer += A[i] * B[i];
	}

	return answer;
}