#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
시저 암호
알파벳을 n만큼 민 문자열
*/

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            answer += " ";
            continue;
        }
        
        int next = s[i] + n;
        if((s[i] <= 'z' && next > 'z') || (s[i] <= 'Z' && next > 'Z')) next -= 26;  // 범위 벗어나면 앞으로 돌림
        answer += (char)next;
    }
    
    return answer;
}