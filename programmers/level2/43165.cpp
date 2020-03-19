#include <string>
#include <vector>
#include <iostream>

using namespace std;

int nsize;
int ans = 0;

void dfs(int idx, int sum, vector<int> numbers, int target) {
	// n개의 숫자 계산 끝나면 타겟과 넘버와 같은지 비교
	if (idx == nsize) {
		if (sum == target) ans++;
		return;
	}

	dfs(idx + 1, sum + numbers[idx], numbers, target);
	dfs(idx + 1, sum - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	nsize = numbers.size();
	dfs(0, 0, numbers, target);
	answer = ans;

	return answer;
}