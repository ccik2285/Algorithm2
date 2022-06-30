#include <iostream>

using namespace std;
int fac(int n){
    if(n==0) return 1;
    else if(n > 1){
        return n*fac(n-1); 
    }
    else{
        return n*1;
    }
}

int main() {
    int n;
    cin >> n;
    cout << fac(n);

}
