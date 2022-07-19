#include <string>
#include <vector>
#include <stack>
using namespace std;
bool check(string s){
    stack<char> c;
    for(auto &a : s){
        if(a == '(') c.push(a);
        else{
            if(!c.empty()){
                c.pop();
            }
            else return false;
        }
    }
    return true;
}

string solution(string p) {
    if(p == "") return ""; // 1번
    string answer = "";
    int left = 0; // (
    int right = 0;  // )
    string u,v = "";
    for(int i = 0; i < p.size(); i++){ 
        if(p[i] == '(') left++;
        else right++;
        
        if(left == right){
            u = p.substr(0,i+1);
            v = p.substr(i+1); // 2번  
            break;
        }
    }

    if(check(u)) answer = u+solution(v); //3 , 3-1번
    else{  //4번
        string temp = "";
        temp = '(' + solution(v) + ')';
        for(int i=1; i < u.size()-1; i++){
            if(u[i] == '(') temp+= ')';
            else temp+='(';
        }
        answer = temp;
    }
    return answer;
}