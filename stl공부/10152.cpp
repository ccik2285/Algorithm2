#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int n, vector<vector<int>> edges){
    int maps[101][101] = {0,}; //그래프 그리기
    bool visited[101] = {false,}; //그래프 순회
    int node_num[3] = {0,};
    int tree =0;
    queue<int> q;
    for(int i=0; i<edges.size(); i++){
        maps[edges[i][0]][edges[i][1]] = 1;
        maps[edges[i][1]][edges[i][0]] = 1; //그래프 
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]) q.push(i);
        else continue;
        int node = 1;
        while(!q.empty()){
        int cur = q.front();
        q.pop();
        visited[cur] = true;
        
        for(int j=0; j<n; j++){
            if(maps[cur][j] && !visited[j]){
                    q.push(j);
                    node++;
                }
            }
        }
        node_num[tree] = node;
        tree++;
    }
    if(tree==3 && (node_num[0] == node_num[1] && node_num[1] == node_num[2])){
        return true;
    }
    return false;

}



vector<int> solution(int n, vector<vector<int>> edges){
    vector<int> answer;
    for(int i=0; i < edges.size()-1; i++){  //조합
        for(int j=i+1; j < edges.size(); j++){
            vector<vector<int>> tmp = edges;
            tmp.erase(tmp.begin()+i);
            tmp.erase(tmp.begin()+j-1);
            if(bfs(n,tmp)){
                answer.push_back(i);
                answer.push_back(j);
            }
        }
    }
    if(answer.empty()) answer.push_back(-1);
    return answer;
}

int main(){
 //   vector<vector<int>> edges = {{0,2},{2,1},{2,4},{3,5},{5,4},{5,7},{7,6},{6,8}};
    vector<vector<int>> tc = {{0,1}, {0,2}, {1,3}, {2,3},{3,4},{4,5},{4,6},{5,7},{6,7},{7,8},{8,9},{8,10},{9,11},{10,11}};
    vector<int> answer = solution(12,tc);
    for(int i=0; i< answer.size(); i++){
        cout << answer[i] << " ";
    }
}