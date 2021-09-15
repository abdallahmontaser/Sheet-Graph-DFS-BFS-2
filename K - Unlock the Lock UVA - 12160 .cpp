#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
string L, U, X; int R, from, to, cur, tem, cnt = 1;
vi len, ve;
void BFS()
{
	len = vi(1e5 + 2, -1);
	queue<int>qe;
	qe.push(from);
	len[from] = 0;
	while (!qe.empty())
	{
		cur = qe.front(), qe.pop();
		if (cur == to)
			break;
		for (auto& it : ve)
		{
			tem = (cur + it) % 10000;
			if (len[tem] == -1)
				qe.push(tem), len[tem] = len[cur] + 1;
		}
	}
}
void solve()
{
	while (cin >> L >> U >> R)
	{
		if (L == "0" && U == "0" && !R)
			break;
		ve = vi(R);
		for (int i = 0; i < R; i++)
			cin >> X, ve[i] = stoi(X);
		from = stoi(L), to = stoi(U);
		BFS();
		cout << "Case " << cnt++ << ": ";
		if (len[to] == -1)
			cout << "Permanently Locked\n";
		else
			cout << len[to] << "\n";
	}
}
int main()
{
	solve();
}
