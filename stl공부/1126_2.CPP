#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s, vector<string> times) {
    vector<int> answer;
    int flag = 1;
    int day = 1;
    int sec = stoi(s.substr(17,2));
    int min = stoi(s.substr(14,2));
    int clk = stoi(s.substr(11,2));
    
    for(int i=0; i < times.size(); i++){
        string s = times[i];
        
        int sec2 = stoi(s.substr(9,2));
        int min2 = stoi(s.substr(6,2));
        int clk2 = stoi(s.substr(3,2));
        if(stoi(s.substr(0,2)) > 0){
            day+= stoi(s.substr(0,2));
        }
        if(sec + sec2 >= 60){
            min++;
        }
        if(min + min2 >= 60){
            clk++;
        }
        if(clk + clk2 >= 24){
            if(stoi(s.substr(0,2)) > 0){
                flag = 0;
            }
            day++;
        }
        sec = (sec + sec2) % 60;
        min = (min + min2) % 60;
        clk = (clk + clk2) % 24;
    }
    
    if(flag) answer.push_back(1);
    else answer.push_back(0);

    answer.push_back(day);


    return answer;
}

int main() {
    string s = "2021:04:12:16:08:35";
    vector<string> t = {"01:06:30:00","01:04:12:00"};

    vector<int> ans = solution(s,t);
    for(int i=0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}