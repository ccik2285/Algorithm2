#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    stack<char> st;
    string s;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> s;
        for(auto& a : s){
        if(a == '('){
            st.push(a);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                cout << "NO" << "\n";
                continue;
            }
        }
    }
    if(st.empty()) cout << "YES"<< "\n";
    else cout << "NO"<< "\n";

    }

}