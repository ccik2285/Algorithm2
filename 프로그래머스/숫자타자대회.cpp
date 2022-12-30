#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

queue<tuple<int, int, int>> q;
int vis[4][3];
int dp[100005][4][3][4][3];
int board[4][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
    { 10, 0, 11 }
};
int coord[12][2] = {
    { 3, 1 },
    { 0, 0 },
    { 0, 1 },
    { 0, 2 },
    { 1, 0 },
    { 1, 1 },
    { 1, 2 },
    { 2, 0 },
    { 2, 1 },
    { 2, 2 },
    { 3, 0 },
    { 3, 2 },
};
int dir1[4][2] = {
    { -1, 0 },
    { 0, 1 },
    { 1, 0 },
    { 0, -1 }
};
int dir2[4][2] = {
    { -1, -1 },
    { -1, 1 },
    { 1, 1 },
    { 1, -1 },
};
string ns;
int n;

int isRange(int y, int x) {
    return y >= 0 && y < 4 && x >= 0 && x < 3;
}

int sol2(int y, int x, int ty, int tx) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            vis[i][j] = 0;

    while (!q.empty()) q.pop();

    vis[y][x] = 1;
    q.push({ y, x, 0 });

    while (!q.empty()) {
        int y, x, d;
        tie(y, x, d) = q.front();
        q.pop();

        for (const auto &dir: dir1) {
            int ny = y + dir[0];
            int nx = x + dir[1];

            if (isRange(ny, nx) && !vis[ny][nx]) {
                if (ny == ty && nx == tx) return d + 2;
                vis[ny][nx] = 1;
                q.push({ ny, nx, d + 2 });
            }
        }

        for (const auto &dir: dir2) {
            int ny = y + dir[0];
            int nx = x + dir[1];

            if (isRange(ny, nx) && !vis[ny][nx]) {
                if (ny == ty && nx == tx) return d + 3;
                vis[ny][nx] = 1;
                q.push({ ny, nx, d + 3 });
            } 
        }
    }

    return 100;
}

int sol(int d, int ly, int lx, int ry, int rx) {
    if (d == n) return 0;

    if (dp[d][ly][lx][ry][rx] != -1) return dp[d][ly][lx][ry][rx];

    auto cur = coord[ns[d] - '0'];

    if ((cur[0] == ly && cur[1] == lx) || (cur[0] == ry && cur[1] == rx))  {
        return dp[d][ly][lx][ry][rx] = 1 + sol(d + 1, ly, lx, ry, rx);
    }

    return dp[d][ly][lx][ry][rx] = min(sol2(ly, lx, cur[0], cur[1]) + sol(d + 1, cur[0], cur[1], ry, rx), sol2(ry, rx, cur[0], cur[1]) + sol(d + 1, ly, lx, cur[0], cur[1]));
}

int solution(string numbers) {
    ns = numbers;
    n = numbers.size();
    memset(dp, -1, sizeof(dp));
    return sol(0, 1, 0, 1, 2);
}