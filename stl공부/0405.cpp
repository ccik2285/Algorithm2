#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    string s = to_string(storey);
    for(int i=s.size()-1; i >= 0; i--){
        if(i==0) {
            if(s[i] > '5'){
                answer += 11 - (s[i] - '0');
            }
            else answer += (s[i] - '0'); 
            break;
        }
        if(s[i] >= '5'){
            answer += 10 - (s[i] - '0');
            s[i-1] = s[i-1] + 1; 
        }
        else {
            answer += (s[i] - '0');
        }
    }
    cout << s;
    return answer;
}