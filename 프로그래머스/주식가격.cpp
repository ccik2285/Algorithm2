#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    //10^4 x 10^4 + n

    for(int i=0; i < prices.size(); i++){
        int cur = prices[i];
        int time = 0;
        for(int j=i+1; j < prices.size(); j++){
            time++;
            if(cur > prices[j]){
                break;
            }
        }
        answer.push_back(time);
    }


    return answer;
}