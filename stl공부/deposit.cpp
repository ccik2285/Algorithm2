#include <iostream>
#include <queue>
using namespace std;
//n,m 잔액,거래량
//deposit -> 입금
//pay -> 출금 잔액보다 작으면 결제 안됨
//reservation -> 잔액보다 작으면 결제대기가 없으면 결제  || 잔액보다 크면 결제대기열에 들어감
int main(){
    int n,m;
    queue<int> q;
    string s;
    int a;
    cin >> n >> m;
    for(int i=0; i < m; i++)
    {
        cin >> s >> a;
        if(s == "deposit")
        {
            n += a;
        }
        else if(s == "pay" && n >= a)
        {
            n -= a;
        }
        else if(s == "pay" && n < a){
            continue;
        }
        else{
            q.push(a);
        }
        while(n >= q.front()){
            int mo = q.front();
            n -= q.front();
            q.pop();
        }
    }
        cout << n;
}