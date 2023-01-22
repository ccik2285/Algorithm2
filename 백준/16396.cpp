// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool cmp(pair<int,int> a,pair<int,int> b){
//     return a.second < b.second;
// }

// int main() {
//     int n; cin >> n;
//     vector<pair<int,int>> vt;
//     int len = 0;
//     for(int i=0; i < n; i++){
//         int a,b;  cin >> a >> b;
//         vt.push_back(make_pair(a,b));
//     }    
//     sort(vt.begin(),vt.end(),cmp);
//     int start = vt[0].first;
//     int end = vt[1].second;
//     for(int i=1; i < vt.size(); i++){
//         if(vt[i-1].second >= vt[i].first){
//             end = vt[i].second;
//         }
//         else if(vt[i-1].second < vt[i].first){
//             len += end - start;
//             start = vt[i].first;
//             end = vt[i].second;
//         }
//     }
//     len += end - start;
//     cout << len;
// }



#include <iostream>
using namespace std;
int N[10001] = { 0 };
int main() {
	int n;
	int a, b;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (; a < b; a++) {
			N[a] = 1;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (N[i] == 1)
			sum++;
	}
	cout << sum;
	return 0;
}