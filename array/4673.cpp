#include <iostream>
#include <vector>

using namespace std;


int num[10001] = { 0, };

int d(int n) {
	int result = n;
	while (true) {
		result += n % 10;
		if (n / 10 == 0) break;
		n = n / 10;
	}

	return result;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int tmp;
	for (int i = 1; i <= 10000; i++) {
		tmp = d(i);
		if(tmp <= 10000) num[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (num[i] == 0) cout << i << "\n";
	}
}