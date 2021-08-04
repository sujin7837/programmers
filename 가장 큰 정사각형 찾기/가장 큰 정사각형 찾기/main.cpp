//
//  main.cpp
//  가장 큰 정사각형 찾기
//
//  Created by 김수진 on 2021/04/27.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> board;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    board.push_back(b);
    cout<<board[0].size();
    
    return 0;
}
