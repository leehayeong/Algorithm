#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 낮에 +Am, 밤에 -Bm, 막대기 높이 Vm
	long long A, B, V;
	cin >> A >> B >> V;

	long long day;
	if ((V - A) % (A - B) == 0) day = (V - A) / (A - B) + 1;
	else day = (V - A) / (A - B) + 2;

	// 며칠 걸리는지 출력
	cout << day;
}

/*
시간초과 코드

	// day일 때 오른 높이가 Vm이 될 때까지 확인하며 몇일인지 센다.
	while (true) {
		// 1. 하루가 지남
		day++;

		// 2. 낮에 Am만큼 올라감
		now += A;

		// 3. 낮에 올라갔을 때, 다 올라갔다면(나무막대보다 높이) 종료
		if (now >= V) break;

		// 4. 아니라면 밤이 오므로 다시 Bm만큼 내려감
		now -= B;
	}
*/