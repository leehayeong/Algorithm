#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
ȸ������ ���̿� �̸� ���Լ����� �Է�
���̰� �����ϴ� ��, ������ ���� ������ ����� ������ ����
*/

int n, age;
string name;
pair<int, pair<int, string>> list[100000];

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	// ���̰� ������ index������.
	if (a.second.first == b.second.first) {
		return a.first < b.first;
	}

	// ���̰� �ٸ��� ���̼�����.
	return a.second.first < b.second.first;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	// �Էµ� ������ ���� index�� �ٿ� ����
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		list[i] = make_pair(i, make_pair(age, name));
	}

	sort(list, list + n, compare);

	for (int i = 0; i < n; i++) {
		cout << list[i].second.first << " " << list[i].second.second << "\n";
	}
}