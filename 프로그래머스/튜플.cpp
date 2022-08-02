#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> temp;
vector<pair<int,vector<int>>> current;
vector<int> solution(string s) {
    vector<int> answer;
    string a = "";
    for(int i=2; i < s.size()-1; i++){
        if(s[i] - '0' >= 0 && s[i] - '0' < 10){
            a +=s[i];
        }
        else if(s[i] == ','){
            if(s[i-1] == '}') continue;
            temp.push_back(stoi(a));
            a = "";
        }
        else if (s[i] == '}') {
			temp.push_back(stoi(a));
			current.push_back(make_pair(temp.size(), temp));
			a = "";
			temp.clear();
		}
    }
    sort(current.begin(), current.end());
    set<int> res;
	for (pair<int, vector<int>> p : current) {
		for (int num : p.second) {
			if (res.find(num) == res.end()) {
				res.insert(num);
				answer.push_back(num);
			}
		}
	}
    return answer;
}