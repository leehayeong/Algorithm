#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	long long N;
	if (C - B <= 0) cout << -1;
	else cout << A / (C - B) + 1;
}