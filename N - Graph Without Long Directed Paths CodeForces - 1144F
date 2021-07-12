#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int N, M, u, ok = 1;
vector<vi>adj;
vi col, ve;
void dfs(int node, int color)
{
	col[node] = color;
	for (auto child : adj[node])
	{
		if (col[child] == -1)
			dfs(child, !color);
		else
			ok &= (col[node] != col[child]);
	}
}
void solve()
{
	cin >> N >> M;
	adj = vector<vi>(N), col = vi(N, -1), ve = vi(M);
	for (int i = 0; i < M; i++)
		cin >> u >> ve[i], adj[u - 1].push_back(ve[i] - 1), adj[ve[i] - 1].push_back(u - 1);
	dfs(0, 0);
	if (!ok)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 0; i < M; i++)
			cout << col[ve[i] - 1];
	}
}
int main()
{
	solve();
}
