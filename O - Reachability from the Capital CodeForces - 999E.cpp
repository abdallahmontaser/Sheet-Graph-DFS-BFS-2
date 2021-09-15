#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define allr(x)                x.rbegin(),x.rend()
int N, M, C, u, v, ans = 0, cnt;
vector<vi>adj;
vi vis1, vis2;
void dfs1(int node)
{
	vis1[node] = 1;
	for (auto child : adj[node])
		if (!vis1[child])
			dfs1(child);
}
void dfs2(int node)
{
	vis2[node] = 1;
	cnt++;
	for (auto child : adj[node])
		if (!vis2[child])
			dfs2(child);
}
void solve()
{
	 cin >> N >> M >> C;
	C--;
	adj = vector<vi>(N);
	vector<pair<int, int>>tem;
	vis1 = vis2 = vi(N, 0);
	for (int i = 0; i < M; i++)
		cin >> u >> v, u--, v--, adj[u].push_back(v);
	dfs1(C);
	for (int i = 0; i < N; i++)
	{
		if (!vis1[i])
		{
			cnt = 0;
			vis2 = vi(N, 0);
			dfs2(i);
			tem.push_back({ cnt,i });
		}
	}
	sort(allr(tem));
	for (auto& it : tem)
		if (!vis1[it.second])
			ans++, dfs1(it.second);
	cout << ans;
}
int main()
{
	solve();
}
