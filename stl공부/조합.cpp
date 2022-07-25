#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a = "200521";
    sort(a.begin(),a.end());
    do {
        cout << a << endl;
    }while(next_permutation(a.begin(),a.end()));
}