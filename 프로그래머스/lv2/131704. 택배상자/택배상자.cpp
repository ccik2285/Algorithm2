#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    int pointer = 0;
    for(int i=1; i <= order.size(); i++){
        st.push(i);
        
        while(!st.empty() && order[pointer] == st.top()){
            pointer++;
            st.pop();
        }
    }
    answer = pointer;
    return answer;
}