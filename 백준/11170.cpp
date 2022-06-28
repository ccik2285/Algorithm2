#include <iostream>
#include <string>
using namespace std;

int main() {
    int a;
    cin >> a;
    int n,m;
    for(int i=0; i<a; i++){
        cin >> n >> m;
        int count = 0;
        for(int j=n; j<m+1; j++){
            string s = to_string(j);
            for(auto& c : s){
                if(c == '0') count ++; 
            }
        }
          cout << count << "\n";
    }    
}

