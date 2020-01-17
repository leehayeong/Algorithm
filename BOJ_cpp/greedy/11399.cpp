#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
ATM
�� �� �ִ� ����� �� N, �� �ɸ��� �ð� Pi
�ð��� ���� �ּڰ���?

1. �ɸ��� �ð� ������� �����Ѵ�.
2. �� �� ����� �ɸ� �ð��� ���� �ɸ� �ð��� �迭�� �����Ѵ�.
3. �迭�� ��� ���� ���Ѵ�.
*/

int n, sum, list[1000], result[1000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	sort(list, list + n);

	result[0] = list[0];
	for (int i = 1; i < n; i++) {
		result[i] = result[i - 1] + list[i];
	}


	for (int i = 0; i < n; i++) {
		sum += result[i];
	}

	cout << sum;
}