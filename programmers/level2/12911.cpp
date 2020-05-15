#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 다음 큰 숫자

int decToBinary(int n) {
	int ret = 0;	// 2진수로 변환했을 때 1의 개수 세기

	while (n > 0) {
		if (n % 2 != 0) ret++;
		n /= 2;
	}

	return ret;
}

int solution(int n) {
	int answer = 0;
	int cnt;

	// n을 이진수로 변환했을 때 1의 개수
	cnt = decToBinary(n);

	// n부터 1씩 증가시키며 2진수로 변환
	while (1) {
		n++;
		if (cnt == decToBinary(n)) {
			answer = n;
			break;
		}
	}

	return answer;
}

int main() {
	cout << solution(78);
}