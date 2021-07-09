#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi>adj;
vi vis, path;
void dfs(int node)
{
	vis[node] = 1;
	path.push_back(node);
	for (auto child : adj[node])
	{
		if (!vis[child])
			dfs(child);
	}
}
void solve()
{
	int N, M, u, v, ans = 0, tem; cin >> N >> M;
	adj = vector<vi>(N);
	vis = vi(N, 0);
	for (int i = 0; i < M; i++)
		cin >> u >> v, adj[u - 1].push_back(v - 1), adj[v - 1].push_back(u - 1);
	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			path.clear();
			tem = 1;
			dfs(i);
			for (auto child : path)
				tem &= (adj[child].size() == 2);
			ans += tem;
		}
	}
	cout << ans;
}
int main()
{
	solve();
}
