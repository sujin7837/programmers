//
//  main.cpp
//  주식가격
//
//  Created by 김수진 on 2021/04/09.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int psize=prices.size();
    
    for(int i=0;i<psize-2;i++) {
        int s=0;
        for(int j=i+1;j<psize;j++) {
            s++;
            if(prices[i]>prices[j]) break;
        }
        answer.push_back(s);
    }
    answer.push_back(1);
    answer.push_back(0);
    
    return answer;
}
