#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

/*
폰켓몬
최대한 많은 종류의 폰켓몬 N/2선택. 종류의 개수
*/

int solution(vector<int> nums)
{
	int answer = 0;
	int size = nums.size();

	// 종류 개수 보기 위해 해시 set 사용
	set<int> s;
	for (int i = 0; i < size; i++) {
		s.insert(nums[i]);
	}

	// 종류의 개수는 set의 크기
	int n = s.size();
	if (n < size / 2) answer = n;
	else answer = size / 2;

	return answer;
}