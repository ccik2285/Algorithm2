#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
//가장 많이 재생된 장르
//많이 재생된 장르 순으로 2곡씩 수록
//장르 내에서 재생횟수가 같으면 고유번호 낮은 순으로 수록



using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> ge;
    map<string,map<int,int>> mu;
    
    for(int i=0; i < genres.size(); i++){
        ge[genres[i]] += plays[i];
        mu[genres[i]][i] = plays[i];
    }
    while(ge.size() > 0){
        int max = 0;
        string genre = "";
        for(auto a : ge){
            if(max < a.second){
                max = a.second;
                genre = a.first;
            }
        } 
        for(int i=0;i < 2; i++)
        {
            int idx = -1;
            int max = 0;
            for(auto a : mu[genre]){
                if(max < a.second){
                    idx = a.first;
                    max = a.second;
                }
            }
            if(idx == -1) break;
            answer.push_back(idx);
            mu[genre].erase(idx);
        }
        
        ge.erase(genre);
        
  }
  
        
    
    return answer;
}