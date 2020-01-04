#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	int n, sum, cnt;
	int score[1000];
	float avg, result;
	for (int i = 0; i < t; i++) {
		cin >> n;
		sum = 0, cnt = 0;
		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		}

		avg = (float)sum / n;

		for (int k = 0; k < n; k++) {
			if (avg < score[k]) cnt++;
		}

		result = (float)cnt / n * 100;

		cout.setf(ios::fixed);
		cout.precision(3);
		cout << result << "%\n";
	}
}