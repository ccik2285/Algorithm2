using namespace std;

long long gcd(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}


long long solution(int w,int h) {
    long long answer = 1;
    answer = (long long)w*h - ((long long)w+h - gcd(w,h)); 
    return answer;
}