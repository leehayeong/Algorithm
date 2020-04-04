#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
이상한 문자 만들기
짝수 알파벳은 대문자, 홀수 알파벳은 소문자로 변환
*/

string solution(string s) {
    string answer = "";
    int length = s.length();
    int idx = 1;
    
    for(int i = 0; i < length; i++){
        if(s[i] == ' ') idx = 0;
        else if (idx % 2 == 0) s[i] = tolower(s[i]);
        else s[i] = toupper(s[i]);
        idx++;
    }
    answer = s;
    
    return answer;
}