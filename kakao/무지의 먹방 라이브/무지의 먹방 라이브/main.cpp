//
//  main.cpp
//  무지의 먹방 라이브
//
//  Created by 김수진 on 2021/08/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(vector<int> food_times, long long k) {
    int answer=0;
    int len=food_times.size();
    vector<pair<int,int>> v;
    
    for(int i=0;i<len;i++) {
        v.push_back({food_times[i],i+1});
    }
    sort(v.begin(), v.end());
    
    int i=0;
    int now=v[i].first;
    if(k<len) {
        answer=v[now].second;
    } else {
        while(i<len) {
            if(now==0) {
                i++;
                now=v[i].first;
            }
            else {
                if(k>=(len-i)*now) k-=(len-i)*now;
                else break;
            }
        }
        answer=v[k].second;
    }
    
    return answer;
}

int main() {
    vector<int> food_times={3, 1, 2};
    long long k=5;
    
    cout<<solution(food_times, k);
    
    return 0;
}
