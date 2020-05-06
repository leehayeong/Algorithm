#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 튜플

vector<int> solution(string s) {
    vector<int> answer;
    
    // 파싱
    vector<pair<int, vector<int>>> list;    // 조합 내 원소 개수, 원소들
    vector<int> element;                   // 원소들
    int length = s.length();
    int cnt = 0;
    int n = 0;
    for(int i = 1; i < length - 1; i++){
        //숫자 시작
        if(s[i] == '{') {
            element.clear();
        }
        // 숫자 끝
        else if (s[i] == '}') {
            element.push_back(n);
            list.push_back(make_pair(cnt, element));
            n = 0;
            cnt = 0;
        }
        // 쉼표
        else if (s[i] == ','){
            if(n != 0){
                element.push_back(n);
                n = 0;
            }
        }
        // 숫자        
        else {
            if(n == 0) {
                cnt++;  // 새로운 숫자
                n = s[i] - '0';
            } 
            else {
                n = (n * 10) + (s[i] - '0');
            }
        }
    }
    
    // 조합의 원소 수가 작은 순으로 정렬
    sort(list.begin(), list.end());
    
    // 튜플 추적
    bool checked[100001] = { false, };
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < list[i].first; j++){
            if(!checked[list[i].second[j]]){
                answer.push_back(list[i].second[j]);
                checked[list[i].second[j]] = true;
            }
        }
    }
    
    return answer;
}