#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> dic;
bool cmp(pair<string,int> a,pair<string,int> b)
{
    if(a.second > b.second) return true;
    else return false;

}


void dfs(string order,string comb,int depth,int idx) {
    if(depth == comb.length())
    {
        dic[comb]++;
        return;
    }
    for(int i=idx; i < order.size(); i++)
    {
        comb[depth] = order[i];
        dfs(order,comb,depth + 1,i+1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i < orders.size(); i++)
    {
        sort(orders[i].begin(),orders[i].end());
        for(int j=0; j<course.size(); j++)
        {
            string tmp = "";
            tmp.resize(course[j]);
            dfs(orders[i],tmp,0,0);
        }
    } 
    vector<pair<string,int>> sorted;
    for(auto a : dic)
    {
        if(a.second > 1)
        {
            sorted.push_back({a.first,a.second});
        }
    }
    sort(sorted.begin(),sorted.end(),cmp);
        for (int i = 0; i < course.size(); i++)
        {
            int max = 0;
            for (int j = 0; j < sorted.size(); j++)
            {
                if (sorted[j].first.length() != course[i])
                {
                    continue;
                }
                else if (max == 0)
                {
                    answer.push_back(sorted[j].first);
                    max = sorted[j].second;
                }
                else if (max == sorted[j].second)
                {
                    answer.push_back(sorted[j].first);
                }
                else
                    break;
            }
        }
        sort(answer.begin(), answer.end());

    return answer;
}