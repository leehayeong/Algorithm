#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
타일 장식물
타일 개수가 N개일 때, 직사각형의 둘레는?
dp[n] = dp[n-1] + dp[n-1]
*/

long long solution(int N) {
    long long answer = 0;
    long long dp[81];
    
    dp[1] = 4;
    dp[2] = 6;    
    
    for(int i = 3; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }    
    
    answer = dp[N];
    
    return answer;
}


/*
//문제를 따라간 풀이
//현재 타일이 N개일 때, 
//가장 큰 사각형의 한 변의 길이가 first 
//first = N-1일 떼 가장 큰 사각형, 두번째로 큰 사각형의 변의 길이를 합한 것
//N개의 넓이 = N-1개일 때 넓이 + (first) * 2
long long solution(int N) {
    long long answer = 0;
    long long dp[81];
    long long first, second;
    
    dp[1] = 4;
    first = 1;
    dp[2] = 6;
    second = 1;
    
    for(int i = 3; i <= N; i++){
        long long next_second = first;  // 현재 가장 큰 길이가, 다음에 두번째로 큰 길이가 됨
        first = first + second;         // 가장 긴 사각형 갱신
        second = next_second;           // 두번째로 긴 사각형 갱신
        dp[i] = dp[i-1] + first * 2;
    }
    
    answer = dp[N];
    return answer;
}
*/