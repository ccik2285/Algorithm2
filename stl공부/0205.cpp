#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <typeinfo>
using namespace std;
vector<int> vt;
vector<int> ans;


int main() {
    int M; cin >> M;
    int fill = M;
    int flag = 0;
    int maxt;
    long long int width = 0;
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
    int low = fill / (maxt*maxt);
    while(maxt % 2 == 0){
        maxt /= 2;
        low *= 4;
    }

    vt.push_back(maxt);
    vt.push_back(maxt);
    vt.push_back(low);

    do{
        long long int bottom = vt[0] * vt[1];
        long long int side = vt[1] * vt[2];
        long long int temp = bottom * 2 + side * 4;
        if(temp < width){
            width = temp;
            ans = vt;
        }
    }while(next_permutation(vt.begin(),vt.end()));
    
    for(int i=0; i < 3; i++) cout << vt[i] << " ";

    
}