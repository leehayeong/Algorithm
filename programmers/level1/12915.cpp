#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
문자열 내 마음대로 정렬하기
n번째 값을 기준으로 문자열 정렬
*/

int idx;

bool cmp(string a, string b){
    if(a[idx] == b[idx]) return a < b;
    return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    
    sort(strings.begin(), strings.end(), cmp);
    answer = strings;
    
    return answer;
}