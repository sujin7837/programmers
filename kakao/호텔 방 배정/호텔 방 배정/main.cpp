//
//  main.cpp
//  호텔 방 배정
//
//  Created by 김수진 on 2021/09/01.
//

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> m;    // key: 방 번호, value: 다음 비어있는 방 저장

long long find_room(long long x) {
    if(m[x]==0) return x;    // x방이 비어있으면, x를 리턴한다.
    else return m[x]=find_room(m[x]);    // x방이 비어있지 않으면, 그 다음 빈 방을 불러온다.
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(long long i:room_number) {
        long long avail_room=find_room(i);    // i방이 비어있는지 확인하고, 비어있지 않으면 다음 빈 방을 저장한다.
        answer.push_back(avail_room);    // 가능한 빈 방을 answer에 저장한다.
        m[avail_room]=avail_room+1;    // 가능한 빈 방 정보를 1만큼 증가시킨다.
    }
    
    return answer;
}

int main() {
    
    
    return 0;
}
