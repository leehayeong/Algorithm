#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

/*
베스트앨범
장르 별로 두 개씩 모아 베스트앨범 출시
많이 재생된 장르 > 많이 재생된 노래 > 고유번호가 낮은 노래
*/

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> m;
    map<string, vector<pair<int, int>>> list;
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i];                           // 장르별 재생 수 집계
        list[genres[i]].push_back(make_pair(i, plays[i]));  // 장르별 index, 재생 수 저장
    }

    // 장르별 재생수로 내림차순 하기 위해 tmp vector에 복사하고 정렬
    vector<pair<string, int>> tmp;
    for(map<string, int>::iterator i = m.begin(); i != m.end(); i++){
        tmp.push_back(make_pair(i->first, i->second));
    }
    sort(tmp.begin(), tmp.end(), compare);

    // 장르 내 재생수 내림차순 정렬
    for(map<string, vector<pair<int, int>>>::iterator i = list.begin(); i != list.end(); i++){
        sort(i->second.begin(), i->second.end(), compare2);
    }
    
    // 가장 많이 재생한 장르부터 2개씩 저장
    for(int i = 0; i < tmp.size(); i++){
        string cur = tmp[i].first;
        answer.push_back(list[cur][0].first);
        if(list[cur].size() == 1) continue;     // 장르에 속한 곡이 한 곡이면, 한 곡만 저장하고 넘어가야 함
        answer.push_back(list[cur][1].first);
    }

    return answer;
}