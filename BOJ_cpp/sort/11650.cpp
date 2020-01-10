#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

/*
좌표 정렬
x순, x같으면 y순
*/

int n;
pair<int, int> arr[100000];

bool compare(pair<int, int> x, pair<int, int> y) {
	if (x.first == y.first) {
		return x.second < y.second;
	}
	return x.first < y.first;
}

int main() { 
	scanf("%d", &n);

	int x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		arr[i] = make_pair(x, y);
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].first, arr[i].second);
	}
}