#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> q;
    for (int i = 0; i < enemy.size(); i++) {
        q.push(enemy[i]);
        n -= enemy[i];
        if (n < 0) {
            if (k == 0) {
                break;
            }
            cout << q.top() << endl;
            n += q.top();
            q.pop();
            k--;
        }
        answer++;
    }
    return answer;
}