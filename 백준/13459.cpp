#include <iostream>
#include <queue>
using namespace std;

char map[11][11];
bool visited[11][11][11][11] = {false};
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct ball{
    int rx,ry;
    int bx,by;
    int count;
    ball(int a,int b,int c,int d,int e) {
        rx = a; ry = b; bx = c; by = d;
        count = e;
    }
};
void go(int &x,int &y,int &dist,int d){
    while(map[x+dx[d]][y+dy[d]] != '#' && map[x][y] != 'O'){
        x += dx[d];
        y += dy[d];
        dist++;
    }

}

void bfs(int rx,int ry,int bx,int by){
    queue<ball> q;
    
    q.push({rx,ry,bx,by,0});
    visited[rx][ry][bx][by] = true;
    while(!q.empty()){
        int rdx = q.front().rx;
        int rdy = q.front().ry;
        int bdx = q.front().bx;
        int bdy = q.front().by;
        int count = q.front().count;
        q.pop();
        if(count >= 10) break;

        for(int i=0; i < 4; i++){
            int tr_x = rdx;
            int tr_y = rdy;
            int tb_x = bdx;
            int tb_y = bdy;
            int rd = 0; int bd = 0;
            int t_count = count;

            go(tr_x,tr_y,rd,i);
            go(tb_x,tb_y,bd,i);
            t_count++;
            if(map[tb_x][tb_y] == 'O') continue;
            if(map[tr_x][tr_y] == 'O') {
                cout << 1;
                return ;
            }
            if (tr_x == tb_x && tr_y == tb_y)
			{
				if (rd > bd) tr_x -= dx[i], tr_y -= dy[i];
				else tb_x -= dx[i], tb_y -= dy[i];
			}

            if(visited[tr_x][tr_y][tb_x][tb_y]) continue;
            visited[tr_x][tr_y][tb_x][tb_y] = true;
            q.push({tr_x,tr_y,tb_x,tb_y,t_count});

        }

    }
    cout << 0;

}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >> m;
    int rx,ry,bx,by;
    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                rx = i;
                ry = j;
            }
            if(map[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }
    bfs(rx,ry,bx,by);
    
}