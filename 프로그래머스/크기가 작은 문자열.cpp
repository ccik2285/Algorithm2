#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int psize = p.size();
    int p_t = stoi(p);
    for(int i=0; i < t.size() - psize; i++){
        string tmp = t.substr(i,psize);
        int i_t = stoi(tmp);
        if(i_t <= p_t) answer++;
    }
    return answer;
}