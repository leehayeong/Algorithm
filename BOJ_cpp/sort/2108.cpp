#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
통계학
산술평균 = N개의 합 / N
중앙값 = 홀수는 N / 2 + 1번째, 짝수는 N / 2, N / 2 + 1번째 수
최빈값 = 가장 많이 나타나는 값
범위 = 최댓값 - 최소값
*/

int avg, mid, mode, range;	// 산술평균, 중앙값, 최빈값, 범위
int n, tmp, sum = 0;
vector<int> arr;
vector<pair<int, int>> cnt_list;

bool compare(pair<int, int> x, pair<int, int> y) {
	if (x.second == y.second) {
		return x.first < y.first;
	}
	return x.second > y.second;
}

int main() { 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		sum += tmp;

		arr.push_back(tmp);
	}
	
	// 산술평균, 반올림 구현
	double ravg = (double)sum / n;
	avg = floor(ravg + 0.5);

	sort(arr.begin(), arr.end());

	// 중앙값
	mid = arr[n / 2];

	// 최빈값
	// 숫자와 빈도수를 pair로 묶어 저장
	int cur = arr[0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (cur == arr[i]) {
			cnt++;
		}
		else {
			cnt_list.push_back(make_pair(cur, cnt));
			cur = arr[i];
			cnt = 1;
		}
	}
	cnt_list.push_back(make_pair(cur, cnt));

	// 빈도수로 sort후, 중복인 경우엔 두 번째로 작은 값으로.
	sort(cnt_list.begin(), cnt_list.end(), compare);
	if (cnt_list.size() >= 2 && cnt_list[0].second == cnt_list[1].second) {
		mode = cnt_list[1].first;
	}
	else {
		mode = cnt_list[0].first;
	}

	// 범위
	range = arr[n - 1] - arr[0];
	
	printf("%d\n%d\n%d\n%d\n", avg, mid, mode, range);
}