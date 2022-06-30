#include <iostream>

using namespace std;
void back(int n,int start,int temp,int end) {
    if(n>1){
        back(n-1,start,end,temp); // 맨위 원반을 end를 거쳐 temp로
        cout << start << " " << end << "\n";
        back(n-1,temp,start,end); //temp에 있던 원반들을 start를 거쳐서 end로
    }
    else{
        cout << start << " " << end << "\n";
    }

}


int main() {
    int n;
    cin >> n;
    cout << (1<<n) -1 << "\n";
    back(n,1,2,3);
}