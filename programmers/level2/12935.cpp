#include <string>
#include <vector>
#include <iostream>

using namespace std;

// N개의 최소공배수 (유클리드 호제법)

int calGcd(int a, int b) {
	int c;
	while (1) {
		c = a % b;
		if (c == 0) break;
		a = b;
		b = c;
	}
	return b;
}

int solution(vector<int> arr) {
	int answer = 1;
	int size = arr.size();

	// 두 수의 최소공배수 = 두 수의 곱 / 두 수의 최대공약수
	int gcd, mul;
	for (int i = 0; i < size; i++) {
		gcd = calGcd(answer, arr[i]);
		mul = answer * arr[i];
		answer = mul / gcd;
	}

	return answer;
}