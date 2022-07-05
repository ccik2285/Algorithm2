#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[100][100];

int bfs(int i,int j,int m,int n,vector<vector<int>> map){
    int size = 0;
    int color = map[i][j];
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n){ //맵을 벗어나면 안됨
                if(map[nx][ny] == color && visited[nx][ny] == false){
                    q.push(make_pair(nx,ny));
                    visited[nx][ny] = true;
                    size++;
                } 
            }
        }
    }
    return size;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }//방문체크 초기화

    for(int i=0; i<m; i++){
        int size;
        for(int j=0; j<n; j++){
            if(picture[i][j] != 0 && visited[i][j] == false){
                size = bfs(i,j,m,n,picture);
                number_of_area++;
                if(size > max_size_of_one_area) max_size_of_one_area = size;
            } 
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main() {
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
    vector<int> answer = solution(6,4,picture);
    cout << answer[0] << " " << answer[1];
}