#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
체육복
잃어 버린 학생들 앞 뒤로 체육복을 빌릴 수 있는지 확인한다.
*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> give(n+1, 1);                   // 가진 체육복 수
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0; i < lost.size(); i++){       // 잃어 버림
        give[lost[i]]--;
    }
    
    for(int i = 0; i < reserve.size(); i++){    // 여벌 체육복을 가지고 있음
        give[reserve[i]]++;                  
    }
    
    for(int i = 1; i <= n; i++){                
        if(give[i] == 0){                       // 체육복 없다면 왼쪽, 오른쪽을 확인하며 빌림
            if(i - 1 >= 1 && give[i - 1] == 2){ //  빌려준 학생은 감소, 받은 학생은 증가
                give[i - 1]--;
                give[i]++;
            } else if (i + 1 <= n && give[i + 1] == 2){
                give[i + 1]--;
                give[i]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){                // 체육복이 한개 이상이면 수업을 들을 수 있음
        if(give[i] >= 1) answer++;
    }
    
    return answer;
}