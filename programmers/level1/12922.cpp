#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
수박수박수박수박수박수?
수박 반복하여 길이 n인 string 만들기
*/

string solution(int n) {
    string answer = "";
    
    if(n % 2 == 0){
        for(int i = 1; i <= n; i += 2) answer += "수박";
    } else {
        for(int i = 1; i < n; i += 2) answer += "수박";
        answer += "수";
    }
    
    return answer;
}