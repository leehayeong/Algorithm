#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
핸드폰 번호 가리기
*/

string solution(string phone_number) {
    string answer = "";
    int length = phone_number.length();
    int hide = length - 4;
    
    for(int i = 0; i < hide; i++) answer += "*";
    answer += phone_number.substr(hide);
    
    return answer;
}