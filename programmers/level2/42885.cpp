#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    int escape_n = 0;

    sort(people.begin(), people.end());
    int min_idx = 0, min, max_idx = n - 1, max;
    while(1){
        // min, max 찾기
        min = people[max_idx];
        max = people[min_idx];

        // 혼자 남은 탈출자라면
        if(max_idx == min_idx){
            answer++;
            escape_n++;
        }
        // 같이 움직일 수 있다면 같이 이동
        else if(min + max <= limit){
            min_idx++;
            max_idx--;
            answer++;
            escape_n += 2;
        } 
        // 그렇지 않다면 최대몸무게부터 탈출
        else {
            max_idx--;
            answer++;
            escape_n++;
        }

        if(escape_n == n) break;    // 모두 탈출
    }

    return answer;
}