#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 계수정렬
// 각 숫자가 나온 값을 count하고 차례로 count만큼 출력해준다.

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