//
//  main.cpp
//  N진수 게임
//
//  Created by 김수진 on 2021/08/04.
//

#include <string>
#include <vector>

using namespace std;

int remain;

string make_n(int x, int n) {    // n진수를 만드는 코드
    string s="";

    if(x==0) return "0";
    while(x!=0) {
        remain=x%n;
        x=x/n;
        if(remain==10) s="A"+s;
        else if(remain==11) s="B"+s;
        else if(remain==12) s="C"+s;
        else if(remain==13) s="D"+s;
        else if(remain==14) s="E"+s;
        else if(remain==15) s="F"+s;
        else s=to_string(remain)+s;
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int start=0;
    string tmp="";

    for(int i=0;i<t*m;i++) {    // 튜브가 말해야 하는 숫자는 t*m자리 이내에 반드시 존재하므로 t*m개의 숫자를 n진법으로 변환한다.
        tmp+=make_n(start++, n);
    }
    
    int i=p;
    while(answer.length()<t) {    // 문자열의 길이가 t에 도달할 때까지 튜브의 순서에 해당하는 문자를 answer에 추가한다.
        answer+=tmp[i-1];
        i+=m;
    }
    return answer;
}

