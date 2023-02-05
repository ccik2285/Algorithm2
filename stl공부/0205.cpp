#include <iostream>
#include <vector>
#include <math.h>
#include <typeinfo>
using namespace std;

int main() {
    int M; cin >> M;
    int fill = M;
    int flag = 0;
    int maxt;
    while(flag==0){
        for(int i=2; i <= sqrt(M); i++){
            int g = i*i;
            if(fill % g == 0){
                maxt = i;
                flag=1;
            }
        }
        if(flag == 0){
            fill++;
        }
    }
    
}