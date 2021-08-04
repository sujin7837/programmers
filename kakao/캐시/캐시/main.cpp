//
//  main.cpp
//  캐시
//
//  Created by 김수진 on 2021/07/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    
    for(int i=0;i<cities.size();i++) {
        for(int j=0;j<cities[i].size();j++) cities[i][j]=tolower(cities[i][j]);
    }
    while(!cities.empty()) {
        if(v.empty()) {
            v.push_back(cities.front());
            cities.erase(cities.begin());
            answer+=5;
        } else {
            auto it=find(v.begin(), v.end(), cities.front());
            if(it==v.end()) {
                answer+=5;
                v.push_back(cities.front());
                cities.erase(cities.begin());
                if(v.size()>cacheSize) v.erase(v.begin());
            } else {
                answer+=1;
                cities.erase(cities.begin());
            }
        }
    }
    
    return answer;
}

int main() {
    vector<string> cities={"Jeju", "jeju"};
    cout<<solution(2, cities)<<endl;
    
    return 0;
}
