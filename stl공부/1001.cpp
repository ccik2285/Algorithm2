#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int mini = 10000;
bool visited[5][5] = {false,};

bool sfind(string word,char a){
    for(int i=0; i < word.size(); i++){
        if(word[i] == a) return true;
    }
    return false;
}

int dfs(vector<string> maps,string word,int cnt,string cur,int row,int col){
    
    if(cur.size() == word.size()){
        cout << cur << endl;
        if(mini > cnt) mini = cnt;
        return mini;
    }


    for(int i=0; i<4; i++){
        int x = dx[i] + row;
        int y = dy[i] + col;
        
        if(visited[x][y]==true) continue;
        if(x < 0 || x >= maps.size() || y < 0 || y >= maps[0].size()) continue;
        if(sfind(word,maps[x][y])) cur+= maps[x][y];
        else if(maps[x][y]!='-') continue;
        cnt++;
        visited[x][y] = true;
        dfs(maps,word,cnt,cur,x,y);
        visited[x][y] = false;
        

    }

    return -1;
}


int solution(vector<string> maps,string word){
    int answer = -1;
    
    answer = dfs(maps,word,0,"",0,0);

    return answer;
}

int main() {
    vector<string> a = {"axc","abc","yea","yyy"};
    string word = "xye";
   
    cout <<  solution(a,word);


}