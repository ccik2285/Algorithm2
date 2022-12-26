#include <iostream>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        int max = 0;
        for(int i=0; i<10; i++) {
            cin >> n;
            if( n > max ) max = n;
        }
        cout << "#" << tc << " " << max << endl;
    }
}