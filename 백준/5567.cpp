#include <iostream>
using namespace std;
 
int n, m;
const int MAX = 501;
int map[MAX][MAX];
bool visited[MAX];
bool sFriend[MAX]; 
int ans = 0;
 
void count() {
    for (int i = 2; i <= n; i++) {
        if (map[1][i] == 1) {
            visited[i] = true; 
            sFriend[i] = true; 
        }
    }
    for (int i = 2; i <= n; i++) {
        if (sFriend[i]) { 
            for (int j = 1; j <= n; j++) {
                if (map[i][j]) { 
                    visited[j] = true; 
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (visited[i]) {
            ans++;
        }
    }
}
 
int main() {
    cin >> n;
    cin >> m;
 
    while (m--) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
 
    count();
    cout << ans;
}
