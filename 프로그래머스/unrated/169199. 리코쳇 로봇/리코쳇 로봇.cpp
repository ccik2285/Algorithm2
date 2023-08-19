#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 2147000000;

void bfs(vector<string> board,int x,int y){
    bool visited[102][102] = {false,};
    
    visited[x][y] = true;
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int cur = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            int nextcur = cur + 1;
            if(((nextx >= board.size() || nextx < 0)
              || (nexty >= board[0].size() || nexty < 0))
              || board[nextx][nexty] == 'D') continue;
            
            while((nextx + dx[i] < board.size() && nextx + dx[i] >= 0)
              && (nexty + dy[i] < board[0].size() && nexty + dy[i] >= 0)){
                if(board[nextx + dx[i]][nexty + dy[i]] == 'D'){
                    break;
                }
                nextx += dx[i];
                nexty += dy[i];
            }
            if(!visited[nextx][nexty]){
                q.push({{nextx,nexty},nextcur});
                visited[nextx][nexty] = true;

            }           
            if(board[nextx][nexty]=='G'){
                if(ans > nextcur){
                    ans = nextcur;
                }
            }
        }
        
    }
    
}


int solution(vector<string> board) {
    int answer = 0;
    
    for(int i=0; i < board.size(); i++){
        for(int j=0; j < board[0].size(); j++){
            if(board[i][j] == 'R'){
                bfs(board,i,j);
            }
        }
    }
    if(ans == 2147000000) answer = -1;
    else answer = ans;
    return answer;
}