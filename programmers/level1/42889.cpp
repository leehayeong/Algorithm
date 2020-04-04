#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
실패율
스테이지에 도달했으나 클리어 못한 사람의 수 / 스테이지에 도달한 사람의 수
실패율이 높은 스테이지부터 내림차순 정렬 후 리턴
*/

bool cmp(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> arrive(N + 2, 0);   // 도착한 사람 수
    vector<int> fail(N + 2, 0);     // 실패한 사람 수
    vector<pair<double, int>> rate; // 실패율, 스테이지 번호
    
    // 입력 받으면서 클리어한 사람 수 셈
    for(int i = 0; i < stages.size(); i++){
        for(int j = 1; j <= stages[i]; j++) arrive[j]++;
        fail[stages[i]]++;
    }
    
    // 실패율 계산하여 스테이지 번호와 묶어 저장
    for(int i = 1; i <= N; i++){
        if(arrive[i] == 0) {                          
            rate.push_back(make_pair(0, i));
            continue;
        }
        double cal = (double)fail[i] / arrive[i];   
        rate.push_back(make_pair(cal, i));
    }
    
    // 정렬 (실패율 내림차순, 같으면 앞 스테이지를 먼저) 후, 답 저장
    sort(rate.begin(), rate.end(), cmp);
    for(int i = 0; i < rate.size(); i++){
        answer.push_back(rate[i].second);
    }
    
    return answer;
}