#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

/*
자리수 내림차순
*/

int n, arr[10];

int main() { 
	scanf("%d", &n);

	// 자릿수 배열에 각 자릿수 저장
	int i = 0;
	int tmp;
	while (n > 0) {
		tmp = n % 10;
		arr[i] = tmp;
		n = n / 10;
		i++;
	}

	sort(arr, arr + 10, greater<int>());

	for (int j = 0; j < i; j++) {
		printf("%d", arr[j]);
	}

}