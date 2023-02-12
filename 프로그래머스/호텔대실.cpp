#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    sort(book_time.begin(), book_time.end());
    for (int i = 0; i < book_time.size(); i++) {
        string st = book_time[i][0];
        string ed = book_time[i][1];
        int stT = stoi(st.substr(0, 2)) * 60 + stoi(st.substr(3));
        int edT = stoi(ed.substr(0, 2)) * 60 + stoi(ed.substr(3)) + 10;
        while (!q.empty() && q.top() <= stT) {
            q.pop();
        }
        q.push(edT);
        answer = max(answer, (int)q.size());
    }
    return answer;
}