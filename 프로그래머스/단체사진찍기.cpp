#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int find_char(vector<char>& v, char c){
    for(int i = 0; i < v.size(); i++)
        if(c == v[i]) return i;
    
    return -1;
}
bool func1(int a, int b, int gap) {// = 
    if(abs(a-b) == gap) return true;
    else return false;
}
bool func2(int a, int b, int gap) {// < 
    if(abs(a-b) < gap) return true;
    else return false;
}
bool func3(int a, int b, int gap) {// >
    if(abs(a-b) > gap) return true;
    else return false;

}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> arr = {'A','C','F','J','M','N','R','T'};
        do {
              bool flag = true;
            for(auto &s : data){
            // arr 에서 찾기 0,2번 = 사람, 1번 = 부등호 ,3번 = 칸 수 
                int a = find_char(arr,s[0]);
                int b = find_char(arr,s[2]);
                int gap = (s[4] - '0') + 1;
                if(s[3] == '=') flag = func1(a,b,gap);
                else if(s[3] == '<') flag = func2(a,b,gap);
                else flag = func3(a,b,gap);
                if(!flag) break;
            }
              if(flag==true) answer++;
        }while(next_permutation(arr.begin(),arr.end()));
    
    return answer;
}

int main() {
    vector<string> data = {"N~F=0", "R~T>2"};
    cout << solution(2,data);
}