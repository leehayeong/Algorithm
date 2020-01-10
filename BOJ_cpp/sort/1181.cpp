#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
단어 정렬
*/

int n;
string list[20000];
string result[20000];

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}

	return a.length() < b.length();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	// 정렬
	sort(list, list + n, compare);

	// 중복제거
	int i, cnt = 0;
	for (i = 0; i < n - 1; i++) {
		if (list[i] != list[i + 1]) {
			result[cnt] = list[i];
			cnt++;
		}
	}
	result[cnt] = list[i];
	cnt++;

	for (int i = 0; i < cnt; i++) {
		cout << result[i] << "\n";
	}
}