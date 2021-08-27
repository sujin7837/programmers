//
//  main.cpp
//  크레인 인형뽑기 게임
//
//  Created by 김수진 on 2021/08/27.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    deque<int> dq;
    
    for(int i=0;i<moves.size();i++) {
        int front=moves[i]-1;
        for(int j=0;j<board.size();j++) {
            if(board[j][front]!=0) {
                if(dq.empty()) dq.push_front(board[j][front]);
                else if(dq.back()==board[j][front]) {
                    cout<<dq.back()<<endl;
                    dq.pop_back();
                    answer+=2;
                } else dq.push_back(board[j][front]);
                board[j][front]=0;
                break;
            }
        }
    }
    
    return answer;
}

int main() {
    vector<vector<int>> board={{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves={1,5,3,5,1,2,1,4};
    
    cout<<solution(board, moves)<<endl;
//    for(int i=0;i<board.size();i++)
//        cout<<board[i][2]<<endl;
    return 0;
}
