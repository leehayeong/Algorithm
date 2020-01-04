#include <iostream>
#include <vector>

using namespace std;


int num[10001] = { 0, };

// 한수 판별. 즉, 세자리 수의 각 자리수의 차이가 일정한지 판별
bool isHansoo(int n) {
	// 1. 각 자릿수의 값 추출
	int one, two, three;
	one = (n / 10) / 10;
	two = (n / 10) % 10;
	three = n % 10;

	// 2. 자릿수마다 차이 구하기
	int first, second;
	first = one - two;
	second = two - three;

	// 3. 차이가 같을 때 한수
	if (first == second) return true;
	return false;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, result;
	cin >> n;

	// 두자리 수는 무조건 한수이다.
	if (n < 100) {
		result = n;
		cout << result;
		return 0;
	}

	// 세자리 수부터 계산
	result = 99;
	for (int i = 100; i <= n; i++) {
		//cout << "* " << i << "\t";
		if (isHansoo(i)) result++;
	}
	cout << result;
}