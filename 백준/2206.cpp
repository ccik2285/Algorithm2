#include <iostream>
#include <queue>
using namespace std;

string map[1001];
int dist[1001][1001][2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;

int bfs() {
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(0,0),1));
    dist[0][0][1] = 1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int r = q.front().second; //벽 여부
        q.pop();

        if(x == n-1 && y == m-1){
            return dist[x][y][r];
        }

        for(int i=0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if((nx < 0 || nx >= n) || (ny < 0 || ny >=m)) continue;
            if(r == 1 && map[nx][ny] == '1') //방문x 그리고 벽
            {
                dist[nx][ny][0] = dist[x][y][1] + 1;
                q.push(make_pair(make_pair(nx,ny),0));
            }
            else if(map[nx][ny] == '0' && dist[nx][ny][r] == 0){ 
                dist[nx][ny][r] = dist[x][y][r] + 1;
                q.push(make_pair(make_pair(nx,ny),r));  
            }
        }

    }
    return -1;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i < n; i++){
        cin >> map[i];
    }
    cout << bfs();
}