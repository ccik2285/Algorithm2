// #include <iostream>
// #include <set>
// using namespace std;

// int main() {
//     set<string> a;
//     a.insert("s");
//     a.insert("b");

//     for(auto s : a){
//         cout << s << endl;

//     }
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	// 1부터 4까지 저장할 벡터 선언
	// 배열도 가능!
	vector<int> v(4);

	// 4부터 1까지 벡터에 저장
	for(int i=0; i<4; i++){
		v[i] = 4-i;
	}

	// prev_permutation을 통해서 이전 순열 구하기
	do{

		for(int i=0; i<4; i++){
			cout << v[i] << " ";
		}

		cout << '\n';

	}while(prev_permutation(v.begin(),v.end()));

	return 0;

}