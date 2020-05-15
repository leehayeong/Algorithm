#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// 124 나라의 숫자

string solution(int n) {
	string answer = "";
	int result;

	while (n > 0) {
		if (n % 3 == 0) {
			result = 4;
			n = n / 3 - 1;
		}
		else {
			result = n % 3;
			n = n / 3;
		}

		// 결과는 뒤집어서 저장되도록
		answer = to_string(result) + answer;
	}

	return answer;
}

//n  1 2 3  4 5  6  7  8  9  10 11 12  13  14  15 16 17 18 19 20 21 22 23 24 25 26 27 28 

//몫 0 0 1  1  1 2  2  2  3  3  3  4  4   4   5 
//남 1 2 0  1  2 0  1  2  0  1  2  0  1   2   0
//   a      a       a        a        a 

//   1 2 4 11 12 14 21 22 24 41 42 44 111 112 114
// 첫번째 자리 3으로 나눈 나머지
// 두번째 자리 3으로 나눈 몫-1 
// 각 자리수가 3의 배수이면 4로 대체