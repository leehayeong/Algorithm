#include <cstdio>
#include <algorithm>

using namespace std;

// 직사각형인지 아닌지. c*c = a*a + b*b

int main() {
	int arr[3];
	
	while (true) {
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0) return 0;

		sort(arr, arr + 3);

		if ((arr[2] * arr[2]) == (arr[0] * arr[0]) + (arr[1] * arr[1])){
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
}