#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long N;		
	cin >> N;

	// °¢ kÃþ¸¶´Ù 1 + 6k*(k+1)/2
	int k = 0;
	while (true) {
		if (1 + 6 * k*(k + 1) / 2 >= N) break;
		k++;
	}

	cout << k + 1;
}