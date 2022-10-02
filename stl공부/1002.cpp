
//배송물이 늦지 않을 경우 배송날 * fee
//배송물이 늦을 경우 (밀린 날짜 * 배송물 갯수 * 100)
//임금 + 지연보상금을 최소로 하는 경우를 구하고 돈을 return 

//fee = 400
// 1 2 3  4
// 3 0 10 4     400 * 3
// 0 0 13 4     


#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> shippings, int fee, int bo) {
    int answer = 0;
    // //옮기는 날짜 수가 n개일때
    // for(int i=1; i < shippings.size(); i++){
    //     for(int j=i; j < shippings.size()-i; j++){
    //         vector<int> temp = shippings;
    //         if(temp[j] != 0){
    //             temp[j] = temp[]
    //         }
    //     }
    // }

    return answer;
}


int main() {
    vector<int> shippings = {3,0,1,2,3,5,0,4};
    cout << solution(shippings,400,100);
}