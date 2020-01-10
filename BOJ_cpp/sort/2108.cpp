#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
�����
������ = N���� �� / N
�߾Ӱ� = Ȧ���� N / 2 + 1��°, ¦���� N / 2, N / 2 + 1��° ��
�ֺ� = ���� ���� ��Ÿ���� ��
���� = �ִ� - �ּҰ�
*/

int avg, mid, mode, range;	// ������, �߾Ӱ�, �ֺ�, ����
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
	
	// ������, �ݿø� ����
	double ravg = (double)sum / n;
	avg = floor(ravg + 0.5);

	sort(arr.begin(), arr.end());

	// �߾Ӱ�
	mid = arr[n / 2];

	// �ֺ�
	// ���ڿ� �󵵼��� pair�� ���� ����
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

	// �󵵼��� sort��, �ߺ��� ��쿣 �� ��°�� ���� ������.
	sort(cnt_list.begin(), cnt_list.end(), compare);
	if (cnt_list.size() >= 2 && cnt_list[0].second == cnt_list[1].second) {
		mode = cnt_list[1].first;
	}
	else {
		mode = cnt_list[0].first;
	}

	// ����
	range = arr[n - 1] - arr[0];
	
	printf("%d\n%d\n%d\n%d\n", avg, mid, mode, range);
}