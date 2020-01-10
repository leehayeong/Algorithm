#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
회원들의 나이와 이름 가입순으로 입력
나이가 증가하는 순, 같으면 먼저 가입한 사람이 앞으로 정렬
*/

int n, age;
string name;
pair<int, pair<int, string>> list[100000];

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	// 나이가 같으면 index순으로.
	if (a.second.first == b.second.first) {
		return a.first < b.first;
	}

	// 나이가 다르면 나이순으로.
	return a.second.first < b.second.first;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	// 입력된 순서에 따라 index를 붙여 저장
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		list[i] = make_pair(i, make_pair(age, name));
	}

	sort(list, list + n, compare);

	for (int i = 0; i < n; i++) {
		cout << list[i].second.first << " " << list[i].second.second << "\n";
	}
}