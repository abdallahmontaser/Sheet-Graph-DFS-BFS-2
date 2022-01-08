#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int dx[] = { 0,0,1, 0,-1, -1,-1,1, 1 };
int dy[] = { 0,1,0,-1, 0 ,-1, 1,1,-1 };
struct state
{
	int x, y, speedx, speedy;
};
int N, M, P, X1, Y1, X2, Y2, X3, Y3, X4, Y4, to_x, to_y, speedX, speedY, len[30][30][7][7];
vector<vi>grid;
bool vaild(int i, int j, int speed_X, int speed_Y)
{
	if (i >= 0 && j >= 0 && i < N && j < M && abs(speed_X) <= 3 && abs(speed_Y) <= 3 && grid[i][j] && len[i][j][speed_X + 3][speed_Y + 3] == -1)
		return true;
	return false;
}
void solve()
{
	cin >> N >> M >> X1 >> Y1 >> X2 >> Y2 >> P;
	grid = vector<vi>(N, vi(M, 1));
	clr(len, -1);
	state tem;
	queue<state>qe;
	qe.push(state{ X1,Y1,0,0 });
	len[X1][Y1][3][3] = 0;
	while (P--)
	{
		cin >> X3 >> X4 >> Y3 >> Y4;
		for (int i = X3; i <= X4; i++)
			for (int j = Y3; j <= Y4; j++)
				grid[i][j] = 0;
	}
	while (!qe.empty())
	{
		tem = qe.front(), qe.pop();
		if (tem.x == X2 && tem.y == Y2)
		{
			cout << "Optimal solution takes ";
			cout << len[tem.x][tem.y][tem.speedx + 3][tem.speedy + 3] << " hops.\n";
			return;
		}
		for (int i = 0; i < 9; i++)
		{
			speedX = tem.speedx + dx[i];
			speedY = tem.speedy + dy[i];
			to_x = tem.x + speedX;
			to_y = tem.y + speedY;
			if (vaild(to_x, to_y, speedX, speedY))
				qe.push(state{ to_x,to_y,speedX,speedY }), len[to_x][to_y][speedX + 3][speedY + 3] = len[tem.x][tem.y][tem.speedx + 3][tem.speedy + 3] + 1;
		}
	}
	cout << "No solution.\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
