#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int solution(vector<int> cost,int x){
    int answer = 0;
    int sum = 0;
    int rest = x;
    for(int i=cost.size()-1; i >=0; i--){
        //30은 10억
        int ze= i;
        if(rest >= cost[i] ){
            rest -= cost[i];
            while(ze >= 30){
                answer += int(pow(2,30)) % 1000000007;
                ze -=30;
            }
        }
    }
    return answer;

}

int main() {
    int n;
    int x;
    cin >> n;
    vector<int> cost(n);
    for(int i=0; i < n; i++){
       cin >> cost[i];
    }
     cin >> x;
    cout << solution(cost,x);

}