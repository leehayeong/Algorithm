#include <string>
#include <vector>

using namespace std;

/*
문자열 다루기 기본
문자열의 길이가 4 혹은 6이고, 숫자로만 이루어져있으면 true
*/

bool solution(string s) {
    int length = s.length();
    
    if(length != 4 && length != 6) return false;
    for(int i = 0; i < s.length(); i++){
        if(!('0' <= s[i] && s[i] <= '9')) return false;
    }
    
    return true;
}