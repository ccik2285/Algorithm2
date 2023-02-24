#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int n = 0;
int m = 0;
 
int max_size = 1 ;
 
int main (void){
    cin>>n>>m;
    string arr[n];
 
    for (int i = 0 ; i < n ; i++){
            cin>>arr[i] ;
    }
    for (int i = 0 ; i < n -1; i++){
        for (int j = 0 ; j < m -1 ; j++){
            for(int k = 1 ; k < min(n,m) ; k++){
                if (i+k < n && j+k < m){
                char value = arr[i][j] ;
                if (arr[i][j+k] == value && arr[i+k][j] == value && arr[i+k][j+k] == value){
                    max_size = max(max_size,(k+1)*(k+1));
             
                }
                }
            }
        }
    }
    
    cout<<max_size<<endl;
   
        
}