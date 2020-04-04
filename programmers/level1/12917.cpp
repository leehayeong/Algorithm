#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
문자열 내림차순으로 배치하기
*/

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), greater<int>());
    answer = s;
    return answer;
}