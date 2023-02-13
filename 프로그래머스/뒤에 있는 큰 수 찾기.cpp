#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
    stack<int> a;
    for(int i=0; i < numbers.size(); i++){
        int n = numbers[i];
        
        while(!a.empty() && (numbers[a.top()] < n)){
            answer[a.top()] = n;
            a.pop();
        }
        a.push(i);
    }
    
    return answer;
}