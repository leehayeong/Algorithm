#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
회의실 n개
시작시간 끝나는시간
최대 사용할 수 있는 회의 수?

1. 끝나는 시간으로 sort
2. 시작 시간이 끝나는 시간과 같거나 큰 첫 번째 회의 택
*/

int n, ts, te, cnt, index;
pair<int, int> list[100000];
//vector<pair<int, int>> result;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

// 현재 인덱스와 이전 회의가 끝나는 시간을 알려주면 
// 다음 회의가 가능한 회의 index 반환
int findTime(int k, int t) {
	int i = k + 1;
	while (i < n && list[i].first < t) i++;
	return i;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ts >> te;
		list[i] = make_pair(ts, te);
	}

	// 끝나는 시간 기준으로 정렬
	sort(list, list + n, compare);

	// index와 끝나는 시간을 주어, index 이후의 다음 회의들 중에서 시작 가능한 회의 찾음
	while (index < n) {
		//result.push_back(list[index]);
		index = findTime(index, list[index].second);
		cnt++;
	}

	cout << cnt;
}