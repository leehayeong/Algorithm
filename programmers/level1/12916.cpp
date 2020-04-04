#include <string>
#include <iostream>
using namespace std;

/*
문자열 내 p와 y의 개수
p개수 = y개수이면 true, 아니면 false
*/

bool solution(string s)
{
    bool answer = true;
    int pcnt = 0, ycnt = 0;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'Y' || s[i] == 'y') ycnt ++;
        else if(s[i] == 'P' || s[i] == 'p') pcnt++;
    }
    
    if(ycnt != pcnt) answer = false;
    
    return answer;
}