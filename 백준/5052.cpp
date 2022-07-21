#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std; 
int main() {
	int n; cin >> n; 
	while (n--) {
		int number; cin >> number; 		
		string result = "YES"; 
		vector <string> vs; 
		for (int i = 0; i < number; i++) {
			string s; cin >> s; 
			vs.push_back(s); 
		}
		sort(vs.begin(), vs.end()); 	
		for (int i = 1; i < number; i++) {			
			if (vs[i].find(vs[i - 1]) == 0) { 
				result = "NO"; 
				break; 
			}
		}
		cout << result << "\n"; 
	}
}