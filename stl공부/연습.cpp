#include <iostream>
#include <vector>
using namespace std;




int solution(string s,string c){
    int answer = 0;
    vector<string> col;
    string tmp = "";
    for(auto a : s){
        if(tmp == "\n"){
            cout << "hello";
            break;
        }
        else if( a== ',' ||  (a < 'A' || a > 'Z') && (a < 'a' || a > 'z')){
            cout << tmp << endl;
            col.push_back(tmp);
            tmp = ""; 
            if( a != ',') tmp += a;
            continue;
        }
        tmp += a;
    }


    return answer;
}


int main() {
  string s = "id,name,age,act,room,dep\n,jack,68,T,13,8\n";
  string c = "age";

  int ans = solution(s,c);
  cout << ans;  
}