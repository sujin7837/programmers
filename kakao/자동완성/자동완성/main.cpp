//
//  main.cpp
//  자동완성
//
//  Created by 김수진 on 2021/08/04.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    int tmp=-1, now=0;
    bool visit=false;
    
    sort(words.begin(), words.end());
    for(int i=0;i<words.size();i++) {
        if(tmp>now) answer+=tmp+1;
        else answer+=now;
        tmp=now;
        if(i==words.size()) break;
        for(int j=0;j<words[i].length();j++) {
            if(words[i][j]==words[i+1][j]) {
                now=j+1;
                visit=true;
            } else {
                if(j==0) {
//                    visit=false;
                    now=j+1;
                    break;
                }
                else break;
            }
        }
    }
    if(visit) answer+=tmp+1;
    else answer+=tmp;
    
    return answer;
}

int main() {
    vector<string> s={"word","war","warrior","world"};
    
    cout<<solution(s)<<endl;
    
    return 0;
}
