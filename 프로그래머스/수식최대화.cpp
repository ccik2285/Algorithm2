#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long calc(long long a,long long b,char op) {
    if(op == '+') return a+b;
    else if(op == '-') return a-b;
    else return a*b;
}
long long solution(string expression) {
    long long answer = 0;
    vector<char> op;
    vector<long long> num;
    vector<char> oper = {'*','+','-'};
    string temp = "";
    for(int i=0; i < expression.size(); i++){
        if(expression[i] == '*' || expression[i] == '-' || expression[i] == '+')
        {
            op.push_back(expression[i]);
            num.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += expression[i];
        }
    }
    num.push_back(stoi(temp));
    long long Max = 0;
    do{
        vector<long long> tmp_num = num;
        vector<char> tmp_op = op;
        for(int i=0; i < oper.size(); i++)
        {
            for(int j=0; j < tmp_op.size(); j++)
            {
                if(oper[i]==tmp_op[j])
                {
                    tmp_num[j] = calc(tmp_num[j],tmp_num[j+1],tmp_op[j]);
                    tmp_op.erase(tmp_op.begin() + j);
                    tmp_num.erase(tmp_num.begin()+j+1);
                    j--;
                }
            }
            if(Max < abs(tmp_num[0])) Max = abs(tmp_num[0]);
        }
        
    }while(next_permutation(oper.begin(),oper.end()));
    answer = Max;
    return answer;
}