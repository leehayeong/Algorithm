#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// ÄÉÀÌ½º T, Ãþ¼ö H, ¹æ ¼ö W, ¼Õ´Ô N
	int T, H, W, N, result;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		result = 0;

		// ²À´ë±âÃþÀÌ ¾Æ´Ï¸é,
		// ¼Õ´Ô % Ãþ ¼ö = YYÃþ
		// (¼Õ´Ô / Ãþ ¼ö) + 1 = XXÈ£
		if (N % H != 0) {
			result = (N % H) * 100;
			result += N / H + 1;
		}
		// ²À´ë±â ÃþÀÌ¸é Ç×»ó H_XÈ£ (È£¼ö´Â ¼Õ´Ô / Ãþ ¼ö)
		else {
			result = H * 100;
			result += N / H;
		}

		cout << result << "\n";
	}
}