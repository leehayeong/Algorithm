#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// �������
// �� ���ڰ� ���� ���� count�ϰ� ���ʷ� count��ŭ ������ش�.

int arr[10001];

int main() { 
	int n, tmp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0) continue;
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	
}