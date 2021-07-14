#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
struct Mines
{
	int x, y, d;
};
int N, ans;
vector<vi>adj;
vector<Mines>ve;
vi vis, topo;
bool ok(int x1, int y1, int d1, int x2, int y2)
{
	if ((x1 - d1 <= x2) && (x1 + d1 >= x2) && (y1 - d1 <= y2) && (y1 + d1 >= y2))
		return true;
	return false;
}
void Built_graph()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (ok(ve[i].x, ve[i].y, ve[i].d / 2, ve[j].x, ve[j].y))
					adj[i].push_back(j);
			}
		}
	}
}
void dfs(int node)
{
	vis[node] = 1;
	for (auto child : adj[node])
		if (!vis[child])
			dfs(child);
	topo.push_back(node);
}
void solve()
{
	cin >> N;
	ans = 0;
	ve = vector<Mines>(N);
	adj = vector<vi>(N);
	vis = vi(N, 0);
	topo.clear();
	for (auto& i : ve)
		cin >> i.x >> i.y >> i.d;
	Built_graph();
	for (int i = 0; i < N; i++)
		if (!vis[i])
			dfs(i);
	vis = vi(N, 0);
	for (int i = N - 1; i >= 0; i--)
		if (!vis[topo[i]])
			dfs(topo[i]), ans++;
	cout << ans << "\n";
}
int main()
{
	int T = 1; cin >> T;
	while (T--)
		solve();
}
