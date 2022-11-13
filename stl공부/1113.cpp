#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int m,vector<int> v){
    int answer = 0;
    vector<int> board(m,0);
    for(int i= 0; i < v.size(); i++){
        int flag = 0;
        for(int j=0; j<m; j++){
            if(m-board[j] < v[i]){
                board[j-1] = v[i];
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        for(int j=m-1; j >=0; j--){
            if(m-board[j] >= v[i]) {board[j] += v[i]; break;}
        }
    }
    for(int i=0; i < m; i++) if(board[i]) answer++;

    return answer;
}

int main() {
    int m = 8;
    vector<int> v(100000,6);
    cout << solution(m,v);
}