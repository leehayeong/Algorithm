#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 문자열 압축
int compression(string s, int length, int n){
    string ret = "";

    // 처음 자르기
    string start = s.substr(0, n);
    
    // 다음 자르면서 같은지 비교
    int cnt = 1;
    int i;
    for(i = n; i < length; i += n){
        string next;
        
        if(i + n >= length) next = s.substr(i);
        else next = s.substr(i, n);
        
        // 같으면 누적 개수 증가
        if(start == next){
            cnt++;
        } 
        // 다르면 지금까지 같았던 문자열 저장
        else {
            if(cnt == 1) ret += start;
            else ret += to_string(cnt) + start;
            
            cnt = 1;
            start = next;
        }
    }
    
    // 마지막
    if(cnt == 1) ret += start;
    else ret += to_string(cnt) + start;
    
    return ret.length();
}

int solution(string s) {
    int answer = 1000;
    int length = s.length();
    
    // 1개부터 length개까지 압축의 모든 경우의 수 
    for(int k = 1; k <= length; k++){
        answer = min(answer, compression(s, length, k));
    }    
    
    return answer;
}