#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 괄호 변환

bool isCorrect(string s){
    int length = s.length();
    stack<char> st;
    
    for(int i = 0; i < length; i++){
        if(s[i] == '(') {
            st.push(s[i]);
        }
        else {
            if(st.empty() || st.top() != '(') return false;
            st.pop();
        }
    }
    
    return true;
}

string recursion(string s){
    // null인 경우 종료
    if(s.length() == 0){
        return "";
    }
    
    // 균형잡힌 문자열 자르기
    int cnt1 = 0, cnt2 = 0;
    int length = s.length();
    string u, v, convert;
    
    for(int i = 0; i < length; i++){
        if(s[i] == '(') cnt1++;
        else cnt2++;
        
        if(cnt1 == cnt2) {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1);
            break;
        }
    }
    
    string ret;
    
    // 올바른 문자열이라면 v 1단계부터 수행
    if(isCorrect(u)){
        ret = u + recursion(v);
    }
    
    // 아니라면 올바른 괄호 문자열 만들기
    else {
        int ulength = u.length();
        ret = "(";       
        ret += recursion(v);
        ret += ")";
        
        for(int i = 1; i < ulength - 1; i++){
            if(u[i] == '(') ret += ")";
            else ret += "(";
        }
    }
    
    // 생성된 문자열에 붙여서 반환    
    return ret;
}

string solution(string p) {
    string answer = ""; 
    answer = recursion(p);    
    return answer;
}