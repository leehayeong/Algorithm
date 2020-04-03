#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
예산
1. middle 값 구하고, 그 이하는 모두 배정
2. 그 이상에 대해서 miidle 값 갱신, 이하 모두 배정
3. 반복
*/

int solution(vector<int> budgets, int M) {
    int answer = 0;         // 상한액
    int n = budgets.size(); // 전체 지방 수
    int cnt = 0;            // 배정 지방 수
    
    // 예산 정렬하고, 상한액 계산
    sort(budgets.begin(), budgets.end()); 
    answer = M / n;        
    
    int start = 0;
    while(1){
        // 상한액 이하 모두 배정하면서, 배정하면 true 체크
        bool flag = false;                      
        while(cnt < n && budgets[start] <= answer){
            M -= budgets[start];
            flag = true;
            cnt++;
            start++;
        }

        // 모든 지방에 배정했거나 남은 금액이 모두 상한액 이상이면, 
        // 마지막 상한액이 고정된 것이므로 종료
        if(cnt == n || flag == false) break;   

        // 상한액 재계산
        answer = M / (n - cnt);
    }  
    
    // 계산한 상한액이 예산들보다 크다면, 최종 상한액은 예산 중 가장 큰 값
    int maxVal = *max_element(budgets.begin(), budgets.end());
    if(answer > maxVal) answer = maxVal;
    
    return answer;
}