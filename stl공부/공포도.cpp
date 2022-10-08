#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> gong){
    int answer = 0;
    sort(gong.begin(),gong.end(),cmp);
    int i =0;
    while(i != gong.size()){
        int a = gong[i];
        if(a <= gong.size() - i){ 
            gong.erase(gong.begin()+i,gong.begin() +i+a);
            i = 0;
        }
        else{
            i++; 
            continue;
        }
        answer++;
    }

    return answer;
}


int main() {
    vector<int> gong = {2,2,2,3,1};

    cout << solution(gong);
}