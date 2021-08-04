//
//  main.cpp
//  다트 게임
//
//  Created by 김수진 on 2021/07/20.
//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string checkStr[6]={"S", "D", "T", "*", "#"};
    string inputStr[5];
    int result[3];
    
    int starti=0;
    int idx=-1;
    
    for(int i=2;i<dartResult.length();i++) {
        if(dartResult[i]>='0' && dartResult[i]<='9' && dartResult[i-1]!='1')  {
            idx++;
            for(int j=starti;j<i;j++) inputStr[idx]+=dartResult[j];
            starti=i;
        }
        if(i==dartResult.length()-1) {
            for(int j=starti;j<=i;j++) inputStr[2]+=dartResult[j];
        }
    }
    for(int i=0;i<3;i++) {
        result[i]=stoi(inputStr[i]);
        if(inputStr[i][1]=='S' || inputStr[i][2]=='S') result[i]=pow(result[i],1);
        else if(inputStr[i][1]=='D' || inputStr[i][2]=='D') result[i]=pow(result[i], 2);
        else if(inputStr[i][1]=='T' || inputStr[i][2]=='T') result[i]=pow(result[i], 3);
        
        if(inputStr[i][2]=='#' || inputStr[i][3]=='#') result[i]*=-1;
        else if(inputStr[i][2]=='*' || inputStr[i][3]=='*') {
            result[i]*=2;
            if(i!=0) result[i-1]*=2;
        }
    }
    for(int i=0;i<3;i++) answer+=result[i];
    
    
    return answer;
}

int main() {
    cout<<solution("10D10T10S")<<endl;
    return 0;
}
