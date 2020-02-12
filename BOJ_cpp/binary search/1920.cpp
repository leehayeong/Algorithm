#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

/*
이분탐색
X가 존재하는지
존재하면 1, 존재하지 않으면 0
*/

int N, M;
int num[100000];
bool flag;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num, num + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		int start, end, middle;
		start = 0;
		end = N - 1;
		flag = false;

		while (start <= end) {
			middle = (start + end) / 2;
			if (x == num[middle]) {
				flag = true;
				break;
			}
			else if (x > num[middle]) {
				start = middle + 1;
			}
			else if (x < num[middle]) {
				end = middle - 1;
			}
		}

		if (flag) cout << "1\n";
		else cout << "0\n";
	}
}