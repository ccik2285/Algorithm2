// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <iostream>

// using namespace std;

// int ans = 1000000;


// void dfs(int cur,int target,int n,int num){
//     if(cur >= target){
//         if(num < ans && cur == target) ans = num;
//         return ;
//     }
//     dfs(cur*3,target,n,num+1);
//     dfs(cur*2,target,n,num+1);
//     dfs(cur+n,target,n,num+1);
    
// }

// int solution(int x, int y, int n) {
//     int answer = 0;
    
//     dfs(x,y,n,0);
//     if(ans == 1000000) answer = -1;
//     else answer = ans;
//     return answer;
// }
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int Max = 1000000;
int solution(int x, int y, int n) {
    int answer = 0;
    int dp[1000001];
    for(int i=0; i < 1000001; i++) dp[i] = -1;
    dp[x] = 0;
    for(int i=x+1; i <= y; i++){
        int a=Max;
        int b=Max;
        int c=Max;
        int d;
        if(i / 3 >= x && (i % 3 == 0)){
            a = dp[i/3] + 1;
        }
        if(i / 2 >= x && (i % 2 == 0)){
            b = dp[i/2] + 1;
        }
        if(i - n >= x){
            c = dp[i-n] + 1;
        }
        d = min(a,b);
        d = min(d,c);
        dp[i] = (d < Max) ? d  : Max;
    }
    answer = (dp[y] < Max) ? dp[y] : -1;
    return answer;
}