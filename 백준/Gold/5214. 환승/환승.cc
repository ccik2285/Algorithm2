#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void) {
	int n, k, m;
	cin >> n >> k >> m;
	vector<vector<int>> hypertube(m + 1);
	vector<vector<int>> station(n + 1);
	for (int i = 1; i <= m ; i++) {
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			hypertube[i].push_back(temp);
			station[temp].push_back(i);
		}
	}
	vector<int> visited(n + 1, -1);
	vector<int> visitedtube(m + 1, -1);
	visited[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int temp = q.front(); q.pop();
		for (int i = 0; i < station[temp].size(); i++) {
			int nexttube = station[temp][i];
			if (visitedtube[nexttube] == -1) {
				visitedtube[nexttube] = 1;
				for (int j = 0; j < hypertube[nexttube].size(); j++) {
					int nextstation = hypertube[nexttube][j];
					if (visited[nextstation] == -1) {
						visited[nextstation] = visited[temp] + 1;
						q.push(nextstation);
					}
				}
			}
		}
	}
	cout << visited[n];
}