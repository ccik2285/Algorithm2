#include <iostream>
#include <string>
#include <map>


using namespace std;
map<string,string> m;
void mkmap(){
    m["zero"] = "0";
    m["one"] = "1";
    m["two"] = "2";
    m["three"] = "3";
    m["four"] = "4";
    m["five"] = "5";
    m["six"] = "6";
    m["seven"] = "7";
    m["eight"] = "8";
    m["nine"] = "9";
}
int solution(string s) {
    
    string tmp = "";
    string result = "";
    for(int i=0; i < s.size(); i++){
       if(isdigit(s[i]) == 0){ //숫자가 아닐경우
            tmp += s[i];
            if(m[tmp] != ""){
                result += m[tmp];
                tmp = "";
            }     

       }
       else result += s[i];
    }
    return stoi(result);
}
int main() {
    mkmap();
    string s ="one4seveneight";
    int a = solution(s);
    cout << a;
}
