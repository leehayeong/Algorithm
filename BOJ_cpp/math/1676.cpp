#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
팩토리얼 0의 개수
뒷자리부터 0이 아닌 수가 나올때까지 0의 개수
예) 10! = 3628800 -> 정답 = 2
*/

int n, five, two, tmp;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	// 0이 나오기 위해서는 5*2 가 반드시 포함되어야 한다.
	// 즉, 5*2를 소인수로 포함하며, 이 쌍의 개수가 정답이다.
	// 팩토리얼이므로 2부터 n까지 소인수를 구한다.
	for (int i = 2; i <= n; i++) {
		tmp = i;
		while (tmp % 5 == 0) {
			five++;
			tmp = tmp / 5;
		}
		while (tmp % 2 == 0) {
			two++;
			tmp = tmp / 2;
		}
	}

	cout << min(five, two);
}