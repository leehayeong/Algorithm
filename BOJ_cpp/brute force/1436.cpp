#include <cstdio>
#include <string>

using namespace std;

/*
종말의 숫자 666
첫 번째 666, 두 번 째 1666, ...오름차순
N번째 수는?
*/


int main() { 
	int cnt = 0;
	int n, i;

	scanf("%d", &n);

	// i에서 666을 찾을 때마다 count++
	for (i = 666; ; i++) {
		if (to_string(i).find("666") != -1) {
			cnt++;
			if (cnt == n) break;
		}
	}

	printf("%d", i);
}