#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {  //s삭제 초로 바꾸기
    int answer = 0;  //11~2 시간 
                    //14~2 분
                    //17~5 초 
                    //24~5 진행된 시간
    vector<int> start_t;
    vector<int> end_t;
    for(int i=0; i < lines.size(); i++){
        //시작시간,끝나는시간 구함
        //1초는 1000
        //시작 시간 = 전체 시간 - 진행되네 시간 + 1
         string h, m, s, ms;
        int ih, im, is, process;
        
        lines[i].pop_back();
        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        process = stof(lines[i].substr(24, 5)) * 1000;
        
        ih = stoi(h) * 3600 * 1000;
        im = stoi(m) * 60 * 1000;
        is = stoi(s) * 1000 + stoi(ms);
        
        start_t.push_back(ih + im + is - process + 1);
        end_t.push_back(ih + im + is);
    }
    for(int i=0; i < lines.size(); i++){
        int end = end_t[i] + 1000;
        int count = 0;
        for(int j=i; j < lines.size(); j++){
            if(start_t[j] < end){
                count++;
            }
        }
        if(count > answer) answer = count;
    }
    return answer;
}

int main() {
    vector<string> lines = {"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"};
   cout <<  solution(lines);
}