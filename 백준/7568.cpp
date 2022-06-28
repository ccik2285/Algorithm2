#include <iostream>

using namespace std;
int weight[201];
int height[201];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> weight[i] >> height[i];
    }
    for(int i=0; i<n; i++){
        int rank = 1;
        for(int j=0; j<n; j++){
            if(weight[i] < weight[j] && height[i] < height[j]){
                rank++;
            }

        }
        cout << rank << " ";
    }
}