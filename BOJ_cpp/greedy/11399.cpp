#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
ATM
줄 서 있는 사람의 수 N, 각 걸리는 시간 Pi
시간의 합의 최솟값은?

1. 걸리는 시간 순서대로 정렬한다.
2. 이 전 사람이 걸린 시간과 내가 걸린 시간을 배열에 저장한다.
3. 배열의 모든 값을 더한다.
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