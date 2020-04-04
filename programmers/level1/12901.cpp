#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
2016년
2016년 1월 1일은 금요일. a월 b일은 무슨 요일?
*/

string solution(int a, int b) {
    string answer = "";
    string week[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    
    for(int i = 0; i < a - 1; i++){     // 직전 달까지 일 수 총 합 구하기
        days += month[i];
    }
    days += b;                          // 현재 달 일 수 더하기
    answer = week[(days - 1) % 7];      // 일수에 따른 요일 구하기
    
    return answer;
}