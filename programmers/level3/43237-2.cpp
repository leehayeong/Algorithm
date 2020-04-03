#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
예산
이분탐색 풀이
*/

int solution(vector<int> budgets, int M) {
    int answer = 0;         // 상한액
    int n = budgets.size(); // 지방 수
    
    // 정렬
    sort(budgets.begin(), budgets.end());
    
    // 주어진 예산의 총 합 구하고 M과 비교
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += budgets[i];
    }
    
    // M으로 모든 예산을 배정할 수 있다면, 최댓값이 정답
    if(sum < M) return budgets[n-1];
    
    // 이분탐색 시작
    int low = 1;
    int high = budgets[n-1];
    while(low <= high){
        // 중간값 설정, 합 초기화
        int mid = (low + high) / 2;
        sum = 0;
        
        // mid 이하는 전액 배정, mid 이후는 모두 mid를 상한액으로 설정하여배정
        for(int i = 0; i < n; i++){
            if(budgets[i] < mid){
                sum += budgets[i];
            }
            else {
                sum += mid;    
            }
        }
        
        // 예산액을 초과하면 high를 낮춰 설정
        if(sum > M){
            high = mid - 1;
        } 
        // 예산액이 남는다면 low를 높이고, 상한액 갱신
        else if (sum < M){
            if(answer < mid) answer = mid;
            low = mid + 1;
        }
        // 예산액과 같아지면 상한액만 갱신
        else {
            answer = mid;
        }
    }
    
    return answer;
}