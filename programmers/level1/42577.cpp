#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
전화번호 목록
접두어이면 false, 접두어가 없으면 true반환
*/

bool solution(vector<string> phone_book) {
    // 정렬하고
    sort(phone_book.begin(), phone_book.end());
    
    // 순서대로 접두어 비교
    for(int i = 0; i < phone_book.size() - 1; i++){
        // 풀이1 find 사용
        if(phone_book[i + 1].find(phone_book[i]) != -1) return false;
        
        // 풀이2 substr 사용
        // if(phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())) return false;
    }
    
    return true;
}