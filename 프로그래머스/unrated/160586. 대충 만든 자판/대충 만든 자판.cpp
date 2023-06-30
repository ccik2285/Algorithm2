#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> Info;
    for(int i=0; i<keymap.size(); i++){
        for(int j=0; j<keymap[i].size(); j++){
           if(Info.find(keymap[i][j])!=Info.end()){
            Info[keymap[i][j]]=min(Info[keymap[i][j]],j+1);
           }
            else{
                Info.insert(make_pair(keymap[i][j],j+1));
            }
        }
    }

        for(int i=0; i<targets.size(); i++){
            int cnt=0;
            for(int j=0; j<targets[i].size(); j++){
                if(Info.find(targets[i][j])!=Info.end()){
                cnt+=Info[targets[i][j]];
                }
                else{
                    cnt=-1;
                    break;
                }
            }
            answer.push_back(cnt);
        }

    return answer;
}


