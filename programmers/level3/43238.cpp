#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
입국심사
이분탐색 사용
걸릴 수 있는 최소 시간, 최대 시간으로 low, high를 설정한 뒤 mid까지 몇 명을 심사할 수 있는지 구한다.
심사 수가 n이 될 때 종료한다.
*/

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // 정렬
    sort(times.begin(), times.end());
    
    // 이분탐색 시작
    long long low = 1;
    long long high = (long long)times[times.size() - 1] * n;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long cnt = 0;

        // 중간값일 때, 각 입국 심사대에서 심사할 수 있는 인원 계산
        for(int i = 0; i < times.size(); i++){
            cnt += mid / times[i];
        }
        
        // 최솟값을 찾기 위해 같을 때에도 high를 낮춰 한 번 더 확인
        if(cnt >= n){   
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    answer = low;
    
    return answer;
}