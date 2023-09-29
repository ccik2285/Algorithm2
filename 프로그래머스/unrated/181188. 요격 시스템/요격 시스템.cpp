#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    
    sort(targets.begin(),targets.end(),cmp);
    int answer = 0;
    int idx = 0;
    while (idx < targets.size())
    {
        int end = targets[idx++][1];
        answer++;
        while (idx < targets.size() && targets[idx][0] < end)
        {
            if (targets[idx][1] < end) end = targets[idx][1];
            idx++;
        }
    }
    return answer;

    
    return answer;
}