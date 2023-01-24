#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return a.first.second < b.first.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int color[200001]; 
    int result[200001]; 
    vector<pair<pair<int,int>,int>> vt; // color, size , number
    for(int i=0; i < n; i++){
        int color,size; cin >> color >> size;
        vt.push_back(make_pair(make_pair(color,size),i));
    }
    sort(vt.begin(),vt.end(),cmp);

    int sum = 0;
    int j=0;
    for(int i=0; i < n; i++){
        for(; vt[i].first.second > vt[j].first.second; j++){
            sum += vt[j].first.second;
            color[vt[j].first.first] += vt[j].first.second;
        }
        result[vt[i].second] = sum - color[vt[i].first.first];
    }

   for (int i = 0; i < n; i++) {
      printf("%d\n", result[i]);
   }

}