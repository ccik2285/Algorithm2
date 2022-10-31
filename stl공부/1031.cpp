#include <iostream>

using namespace std;

int main(){
    int a =7;
    int n;
    long long int re = 1;
    cin >> n;
    for(int i=1; i <=n; i++){
        re *= a;
    }
    cout << re;
}