#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> list;
    
    // 옷의 종류를 key로, 같은 종류일 때마다 ++ = 종류별 개수 세기
    for(int i = 0; i < clothes.size(); i++){
        list[clothes[i][1]]++;
    }
    
    // (종류별 개수 + 안입는 경우의 수 1)를 곱해 모든 경우의 수 구하기 
    map<string, int>::iterator i;
    for(i = list.begin(); i != list.end(); i++){
        answer *= (i->second + 1);
    }
    
    // 모두 안입는 수인 1 빼기
    answer--;
    
    return answer;
}