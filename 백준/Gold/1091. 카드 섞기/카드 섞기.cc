#include <iostream>
#include <vector>
using namespace std;
vector<int> p,s,d;

bool check(vector<int> curr,vector<int> p){ //완성되었는가
    for(int i=0; i < curr.size(); i++){
        int playernum = i % 3;
        if(p[curr[i]] != playernum) return false;
    }
    return true;
}

bool cant(vector<int> curr){
    for(int i=0; i < curr.size(); i++){
        if(curr[i] != i) return false;
    }
    return true; //만들 수 없음
}


int main() {
    int n;
    cin >> n;
    for(int i=0; i < n; i++) d.push_back(i);
    for(int i=0; i < n; i++){
        int tmp; cin >> tmp;
        p.push_back(tmp);
    }
    for(int i=0; i < n; i++){
        int tmp; cin >> tmp;
        s.push_back(tmp);
    }
    int cnt = 0;
    //계속 섞었는데 처음과 같다면 -1 리턴
    while(1){ //무한 섞기
        if(check(d,p)){
            cout << cnt;
            break;
        }
        vector<int> tmp = d;
        for(int i=0; i < s.size(); i++){
            tmp[s[i]] = d[i];
        }
        d = tmp;
        cnt++;
        if(cant(d)){
            cout << -1;
            break;
        }
        
    }


}