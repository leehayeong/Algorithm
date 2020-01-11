#include <cstdio>
#include <algorithm>

using namespace std;

/*
소인수분해 하는 프로그램
= 모든 약수 구하기(중복해서)
*/

int n;

int main() {
	scanf("%d", &n);

	int idx = 2;
	while (n > 1) {
		for (int i = idx; i <= n; i++) {
			// n이 i로 나누어지면, 약수이므로 출력하고
			// 다음 소인수를 찾기 위해
			// n을 몫으로 변경하고, 시작점도 i로 변경
			if (n % i == 0) {
				printf("%d\n", i);
				n = n / i;
				idx = i;
				break;
			}
		}
	}
}