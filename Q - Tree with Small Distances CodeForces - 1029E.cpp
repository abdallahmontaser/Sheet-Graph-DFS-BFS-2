#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
priority_queue<pair<int, int>>qe;
vector<vi>adj;
vi vis, par;
void dfs_Build(int node, int prev, int dep)
{
	if (dep > 2)
		qe.push({ dep,node });
	for (auto child : adj[node])
	{
		if (child != prev)
		{
			dfs_Build(child, node, dep + 1);
			par[child] = node;
		}
	}
}
void dfs(int node, int dep)
{
	vis[node] = 1;
	for (auto child : adj[node])
		if (!vis[child] && dep + 1 <= 2)
			dfs(child, dep + 1);
}
void solve()
{
	int N, u, v, cur, ans = 0; cin >> N;
	adj = vector<vi>(N);
	vis = par = vi(N);
	for (int i = 0; i < N - 1; i++)
		cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
	dfs_Build(0, -1, 0);
	dfs(0, 0);
	while (qe.size())
	{
		cur = qe.top().second;
		qe.pop();
		if (!vis[cur])
		{
			ans++;
			dfs(par[cur], 1);
		}
	}
	cout << ans;
}
int main()
{
	solve();
}
