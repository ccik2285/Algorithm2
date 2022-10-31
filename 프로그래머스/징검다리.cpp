#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    long long answer = 0; 
    long long left = 0;
    long long right = distance;
    sort(rocks.begin(),rocks.end());
    
    while(left <= right){
        long long mid = (left+right)/2;
        long long prev = 0;
        int cnt = 0; //제거해야 할 바위 수
        //찾는 것 = 바위 사이 거리 최솟값 중 최대값 = mid
        for(int i=0; i<rocks.size(); i++){
            if(rocks[i] - prev >= mid) prev = rocks[i];
            else cnt++;
        }
        if(cnt > n){
            right = mid-1;
        }
        else {
            answer = max(answer,mid);
            left = mid+1;
        }
        
        
    }
    return answer;
}