#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int map[1001][1001];
    for(int i=0; i < board.size(); i++){
        for(int j=0; j < board[0].size(); j++){
            map[i][j] = board[i][j];
        }
    }
    for(int i=1; i < board.size(); i++){
        for(int j=1; j < board[0].size(); j++){
            if(board[i][j]){
                map[i][j] = 1 + min({map[i-1][j-1],map[i-1][j],map[i][j-1]});
                answer = max(answer,map[i][j]);
            }
        }
    }
    
    
    return answer*answer;
}