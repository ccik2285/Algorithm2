#include <iostream>
#include <vector>
using namespace std;
#define LMAX 3000000
#define MLMAX 3000000
int zombie[LMAX+1];
bool timer[LMAX+MLMAX+1];
int main() {
    int l,ml,mk,c;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> l >> ml >> mk >> c;

    for(int i=0; i<l; i++){
        cin >> zombie[i];
    }
    int damage = 0;
    for(int i=0; i<l; i++){
        if(timer[i]){ //damage - 살상력
            damage -= mk;
        }
        if(damage + mk >= zombie[i]){
            damage += mk;
            timer[i+ml] = 1;
        }
        else {
            if(c > 0) c--;
            else{
                cout << "NO";
                return 0;
            }
        }
    }
      cout << "YES";

}