#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
ȸ�ǽ� n��
���۽ð� �����½ð�
�ִ� ����� �� �ִ� ȸ�� ��?

1. ������ �ð����� sort
2. ���� �ð��� ������ �ð��� ���ų� ū ù ��° ȸ�� ��
*/

int n, ts, te, cnt, index;
pair<int, int> list[100000];
//vector<pair<int, int>> result;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

// ���� �ε����� ���� ȸ�ǰ� ������ �ð��� �˷��ָ� 
// ���� ȸ�ǰ� ������ ȸ�� index ��ȯ
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

	// ������ �ð� �������� ����
	sort(list, list + n, compare);

	// index�� ������ �ð��� �־�, index ������ ���� ȸ�ǵ� �߿��� ���� ������ ȸ�� ã��
	while (index < n) {
		//result.push_back(list[index]);
		index = findTime(index, list[index].second);
		cnt++;
	}

	cout << cnt;
}