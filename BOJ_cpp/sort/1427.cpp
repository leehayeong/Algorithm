#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

/*
�ڸ��� ��������
*/

int n, arr[10];

int main() { 
	scanf("%d", &n);

	// �ڸ��� �迭�� �� �ڸ��� ����
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