//
//  main.cpp
//  실패율
//
//  Created by 김수진 on 2021/08/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> &a, pair<double, int> &b) {    // pair<double, int>를 비교하는 함수를 만든다.
    if(a.first==b.first) return a.second<b.second;    // 첫 번째 요소의 값이 같을 경우, 두 번째 요소가 더 작은 것을 리턴한다.
    else return a.first>b.first;    // 첫 번째 요소의 값이 다를 경우, 첫 번째 요소가 더 큰 것을 리턴한다.
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int sum=0, len;
    int num[501]={0,};    // 현재 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수를 저장한다.
    int tot[501]={1,};    // 현재 스테이지에 도달한 사용자의 수를 저장한다.
    vector<pair<double, int>> rate;    // 실패율과 현재 스테이지를 저장하는 벡터 rate를 만든다.
    double r;
    
    len=stages.size();
    for(int i=0;i<len;i++) {    // 스테이지별로 도달했으나 아직 클리어하지 못한 사용자의 수를 저장한다.
        num[stages[i]]++;
    }
    tot[1]=len;    // 첫 번째 스테이지는 모든 사용자가 도달했으므로 stages의 길이를 tot에 저장한다.
    r=(double)num[1]/(double)tot[1];    // 첫 번째 스테이지의 실패율을 구한다.
    rate.push_back({r,1});
    for(int i=2;i<=N;i++) {
        tot[i]=tot[i-1]-num[i-1];    // i번째 스테이지에 도달한 사용자의 수 = i-1번째 스테이지에 도달한 사용자의 수 - i-1번째 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수
        if(tot[i]==0) tot[i]=1;    // 값이 0으로 나눠지지 않도록 한다.
        r=(double)num[i]/(double)tot[i];    // i번째 스테이지의 실패율을 구한다.
        rate.push_back({r,i});
    }
    sort(rate.begin(), rate.end(), cmp);    // 실패율을 기준으로 정렬을 한다.
    for(int i=0;i<N;i++) answer.push_back(rate[i].second);    // 정렬된 rate의 스테이지를 출력한다.
    
    return answer;
}

int main() {
    
    
    return 0;
}
