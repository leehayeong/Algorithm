#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

/*
잘못된 수를 부를때마다 0을 외쳐, 최근에 쓴 수를 지운다.
모든 수를 받아적은 후, 그 수의 합은?
*/

int main() {
	stack<int> s;
	int k, t;
	scanf("%d", &k);

	while (k--) {
		scanf("%d", &t);

		// 0이 아닐 경우에는 값을 쓴다.
		if (t != 0) {
			s.push(t);
			continue;
		}

		// 0일 경우에는 최근에 쓴 수를 지운다.
		s.pop();
	}

	int sum = 0;
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}

	printf("%d", sum);
}