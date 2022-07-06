#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(auto a: new_id){
        answer += tolower(a);  //소문자로 치환
        
        int size = answer.size();
        for(int i=0; i<size; i++){
            if((answer[i] < 'a' || answer[i] > 'z') && (answer[i]<'0' || answer[i] > '9')&& answer[i] !='-' && answer[i] !='_'&& answer[i] !='.'){
                answer.erase(i,1);
                i--; size--;
            } // 소문자,숫자 아닌거 빼기
        }
        int flag = 0;
        for(int i=0; i<size; i++){
            if(answer[i] != '.') flag =0;
            if(flag) {
                answer.erase(i,1);
                i--; size--;
            }
            else{
                if(answer[i]=='.') flag = 1;
                else flag = 0;
            }
        }
    }
    if(answer[0]== '.') answer.erase(0,1);
    if(answer[answer.size()-1] == '.') answer.erase(answer.size()-1,1);
    if(answer == "") answer = 'a';
    if(answer.size() >=16) {answer.erase(15);
        if(answer[answer.size()-1]=='.') answer.erase(answer.size()-1,1);
    }
    if(answer.size() <=2) {
        char a = answer[answer.size()-1];
        while(answer.size() != 3){
            answer +=a;
        }
    }
    return answer;
}