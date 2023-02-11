
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution2(string s, string skip, int index) {
    string answer = "";

    for(auto v : s)
    {
        int t = 0;
        int c = v - 'a';
        while(t < index)
        {
            c++;
            v = (c % 26) + 'a';
            if(skip.find(v) == string::npos)
            {
                t++;
            }
        }
        answer += v;
    }
    return answer;
}
