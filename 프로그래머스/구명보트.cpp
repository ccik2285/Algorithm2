#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int head = 0, tail = people.size()-1;
    sort(people.begin(), people.end()); // 오름차순으로 정렬 

    while(head <= tail){
        if(people[head] + people[tail] <= limit){ 
            head++; 
            tail--;
        }else{ 
            tail--;
        }
        answer++;
    }
    return answer;
}