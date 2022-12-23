#include <iostream>

using namespace std;

int main(){
    int n=0;
    for(int i=0; i <= 110; i++){
        if(i%4==0) n++;
        else if(i%5==0) n++;
        else if(i%6==0) n++;
    }

    cout << n;

}