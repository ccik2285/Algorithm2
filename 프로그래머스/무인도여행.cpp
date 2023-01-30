#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[101][101] = {false,}; 
int bfs(vector<string> maps,int x,int y){
    int cnt = maps[x][y]-'0';
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int startx = q.front().first;
        int starty = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++){
         int nx = startx + dx[i];
         int ny = starty + dy[i];
            
            if((nx < 0 || nx >= maps.size() || (ny < 0 || ny >= maps[0].size()))) continue;
            if(maps[nx][ny] != 'X' && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
                cnt += maps[nx][ny] - '0';
            }
        }
    }
    return cnt;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i=0; i < maps.size(); i++){
        for(int j=0; j < maps[0].size(); j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                visited[i][j] = true;
                answer.push_back(bfs(maps,i,j));
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}