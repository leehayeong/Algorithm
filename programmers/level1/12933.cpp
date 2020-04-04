#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
정수 내림차순으로 배치하기
스트링 이용해 정렬
*/

long long solution(long long n) {
    long long answer = 0;
    
    string num = to_string(n);
    sort(num.begin(), num.end(), greater<int>());
    answer = stoll(num);    // long long으로의 변환은 stoi가 아닌 stoll
    
    return answer;
}