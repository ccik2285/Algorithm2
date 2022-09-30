#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    
    long long low = 0;
    long long high =(long long) times[times.size()-1] * n;
    long long mid;
    while(low <= high){
        long long people = 0;
        mid = (low + high) / 2;
        for(int i=0; i < times.size(); i++)
        {
            people+= (mid/times[i]);
        }
        if(people >= n){
            if(mid <=high){
                answer = mid;
            } 
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    answer = mid;
    return answer;
}