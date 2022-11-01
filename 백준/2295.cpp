#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
vector<int> vret;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end()); 
	for(int i = 0; i < v.size(); i++){
		for(int j = i; j < v.size(); j++){
			int ret = v[i] + v[j];
			vret.push_back(ret);	
		}
	}
	sort(vret.begin(),vret.end());
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(binary_search(vret.begin(), vret.end(), v[i]-v[j])){ 
				cout << v[i];
				return 0;
			}
		}
	}
}