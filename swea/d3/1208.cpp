#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;

/*
Flatten
주어진 횟수만큼 옮겼을 때, 최고점과 죄저점의 차이?
*/

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T = 10;
	for (int t = 1; t <= T; t++) {
		int dump, map[100];
		cin >> dump;

		for (int i = 0; i < 100; i++) {
			cin >> map[i];
		}

		// dump 횟수만큼 최고점-1, 최저점+1을 반복하면 됨.
		for (int i = 0; i < dump; i++) {
			sort(map, map + 100);
			map[0]++;
			map[99]--;
		}

		sort(map, map + 100);
		cout << "#" << t << " " << map[99] - map[0] << "\n";
	}

	return 0;
}