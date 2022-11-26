#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int solution(vector<string> id_list, int k) {
    int answer = 0;
    map<string,int> mp;
    for(int i=0; i < id_list.size(); i++){
        set<string> st;
        string s;
        string str = id_list[i];
        stringstream stream;
        stream.str(str);
        while(stream >> s){
            st.insert(s);
        }
        for(auto a : st){
            if(mp[a] < k){
                mp[a]++;
            }
        }

    }
    for(auto a : mp){
        answer +=mp[a.first];
    }
    return answer;
}

int main() {
    vector<string> id = {"JAY","JAY ELLE JAY MAY","MAY ELLE MAY","ELLE MAY","ELLE ELLE ELLE","MAY"};
    vector<string> id2 = {"A B C D","A D","A B D","B D"};
    cout << solution(id2,2);
}