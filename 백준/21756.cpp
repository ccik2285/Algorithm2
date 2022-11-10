#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vt;
    int n; cin >>n;
    for(int i=1; i <= n; i++){
        vt.push_back(i);
    }

    while(vt.size() != 1){
        int v_size = vt.size();
        for(int i=vt.size()-1; i >= 0;){
            if(vt.size() % 2 != 0) //홀수일때
            {
                vt.erase(vt.begin() + i);
            }
            else{
                vt.erase(vt.begin() + i-1);
            }
            i -=2;
        }

    }

    cout << vt[0];
}