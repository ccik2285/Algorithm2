#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[101][101];  // 배열 입력
int dist[101][101]; //거리 저장할 배열
int n,m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[101][101] = {false,};
int bfs(){

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    dist[0][0] = 1;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];

            if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue; //맵을 벗어남
            if(arr[nextx][nexty] == 1 && !visited[nextx][nexty]){
                q.push({nextx,nexty});
                visited[nextx][nexty] = true;
                dist[nextx][nexty] = dist[curx][cury] + 1; 
            }
        }

    }
    return dist[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; ++i){            

        string row;                   
        cin >> row;

        for (int j=0; j<m; ++j){        
            arr[i][j] = row[j]-'0';    
        }
    }
    cout << bfs();
}
