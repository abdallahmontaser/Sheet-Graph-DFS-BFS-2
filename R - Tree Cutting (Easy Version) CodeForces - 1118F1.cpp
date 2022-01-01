#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int N, u, v, cnt_R = 0, cnt_B = 0, ans = 0;
vector<vi>adj;
vi col;
pair<int, int>dfs(int node, int pref)
{
	int r = (col[node] == 1);
	int b = (col[node] == 2);
	for (auto& child : adj[node])
	{
		if (child != pref)
		{
			pair<int, int>temp = dfs(child, node);
			r += temp.first;
			b += temp.second;
			ans += (temp.first == cnt_R && !temp.second);
			ans += (temp.second == cnt_B && !temp.first);
		}
	}
	return make_pair(r, b);
}
void solve()
{
	cin >> N;
	adj = vector<vi>(N);
	col = vi(N);
	for (auto& it : col) cin >> it, cnt_R += (it == 1), cnt_B += (it == 2);
	for (int i = 0; i < N - 1; i++)
		cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
	dfs(0, -1);
	cout << ans;
}
int main()
{
	solve();
}
