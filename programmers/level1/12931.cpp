#include <iostream>

using namespace std;

/*
자릿수 더하기
*/

int solution(int n)
{
    int answer = 0;
    
    int i = 10;
    while(n >= 1){
        answer += n % i;
        n = n / i;
    }

    return answer;
}