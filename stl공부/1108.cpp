#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<bool> solution(vector<string> members, vector<vector<string>> commands, vector<string> messageIDs) {
    vector<bool> answer;
    stack<string> mes;

    for(int i = 0; i < commands.size(); i++){
        if(commands[i][1] == "MY"){
            while(!mes.empty()){
                string num = mes.top();
                mes.pop();
                for(int j=0 ; j < messageIDs.size(); j++){
                    if(messageIDs[j] == num) {answer.push_back("true"); cout << commands[i][2] << endl; break;}
                }
            }
        }
        else{
            mes.push(commands[i][2]);
        }
    }
    while(!mes.empty()){
        string num = mes.top();
        mes.pop();
        for(int j=0 ; j < messageIDs.size(); j++){
            if(messageIDs[j] == num) {answer.push_back("false"); break;}
        }
    }

    return answer;
}
int main() {
    vector<string> m = {"A","B"};
    vector<vector<string>> co = {{"W","MY","1"},{"W","A","7"},{"W","B","4"},{"W","MY","9"},{"W","A","11"},{"R","B",""}};
    vector<string> id = {"7","11"};
    solution(m,co,id);
}