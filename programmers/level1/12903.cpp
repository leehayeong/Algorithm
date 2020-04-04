#include <string>
#include <vector>

using namespace std;

/*
가운데 글자 가져오기
단어의 가운데 글자 반환 (짝수는 두 글자)
*/

string solution(string s) {
    string answer = "";
    int length = s.length();
    
    if(length % 2 == 0){
        answer = s.substr(length / 2 - 1, 2);
    } else {
        answer = s[length / 2];
    }
    
    return answer;
}