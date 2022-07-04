#include <iostream>

using namespace std;

void back(int i,int j,int n) {
    if((i/n) % 3 == 1 && (j/n) % 3 == 1){
        cout << " ";
    }
    else{
        if(n/3 == 0){
            cout << "*";
        } //재귀 종료 조건
        else{
          back(i,j,n/3);   
        }
    }
}


int main() {
    int n;
    cin >> n ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            back(i,j,n);
        }
        cout << "\n";
    }
}