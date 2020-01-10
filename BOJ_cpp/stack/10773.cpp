#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

/*
�߸��� ���� �θ������� 0�� ����, �ֱٿ� �� ���� �����.
��� ���� �޾����� ��, �� ���� ����?
*/

int main() {
	stack<int> s;
	int k, t;
	scanf("%d", &k);

	while (k--) {
		scanf("%d", &t);

		// 0�� �ƴ� ��쿡�� ���� ����.
		if (t != 0) {
			s.push(t);
			continue;
		}

		// 0�� ��쿡�� �ֱٿ� �� ���� �����.
		s.pop();
	}

	int sum = 0;
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}

	printf("%d", sum);
}