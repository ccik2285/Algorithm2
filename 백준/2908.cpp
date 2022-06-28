#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string a,b;
    a = to_string(n);
    b = to_string(m);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    n = stoi(a);
    m = stoi(b);

    if(n > m) cout << a;
    else cout << b;
}