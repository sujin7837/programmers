//
//  main.cpp
//  124 나라의 숫자
//
//  Created by 김수진 on 2021/04/20.
//

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string arr[3]={"4","1","2"};
    
    while(n) {
        answer=arr[n%3]+answer;
        if(!(n%3)) n=n/3-1;
        else n/=3;
    }
    
    return answer;
}
