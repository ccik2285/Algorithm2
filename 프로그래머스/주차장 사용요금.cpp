#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int diff(string in,string out){
    int dif = 0;
    int in_h = stoi(in.substr(0,2));
    int in_m = stoi(in.substr(3,2));
    int out_h = stoi(out.substr(0,2));
    int out_m = stoi(out.substr(3,2));

    dif = ((out_h*60)+(out_m)) - ((in_h*60)+(in_m)) ;
    return dif;
    
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,vector<string>> car;    
    stringstream ss;
    for(auto a: records){
        ss.str(a);
        string time,number,type; 
        ss >> time >> number >> type;
        ss.clear();
        car[number].push_back(time);
    }
    
    for(auto c : car){
        int sum = 0;
        if(c.second.size() & 1){
            c.second.push_back("23:59");
        }
        vector<string> tmp = c.second;
        for(int i=0; i<tmp.size()-1; i+=2){
            sum += diff(tmp[i],tmp[i+1]);
            
        }
        cout << sum << endl;
        if(sum > fees[0]){
            answer.push_back(fees[1] + ceil((sum-fees[0])/(double)fees[2])*fees[3]);
        }
        else answer.push_back(fees[1]);
        
    }
    return answer;
}