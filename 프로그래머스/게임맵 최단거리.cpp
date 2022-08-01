#include <iostream>
#include<vector>
#include <queue>
using namespace std;
struct can{
    int x;
    int y;
    can(int _x,int _y) { x = _x; y = _y;}
};
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 }; 
int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n,vector<int>(m));
    vector<vector<int>> dist(n,vector<int>(m));
    int answer = 0;
    queue<can> q;
    q.push(can(0,0));
    visited[0][0] = 1;
    dist[0][0] = 1;
    while(!q.empty()){
        can cu = q.front();
        q.pop();
        int now_x = cu.x;
        int now_y = cu.y;
        for(int i=0; i <4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(next_x >= m || next_x < 0 || next_y >= n || next_y < 0) continue;
            if(maps[next_y][next_x]==0) continue;
            if(visited[next_y][next_x]) continue;

            q.push(can(next_x,next_y));
            dist[next_y][next_x] = dist[now_y][now_x] + 1;
            visited[next_y][next_x] = 1;
        }
    }
    if(!visited[n - 1][m - 1])
        return -1;
    else
        return dist[n - 1][m - 1];

}