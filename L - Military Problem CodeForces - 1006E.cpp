#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
int N, Q, X, u, k, cnt = 0;
vector<vi>adj;
vi ve, save, len;
int dfs(int node)
{
	ve.push_back(node);
	save[node] = cnt++;
	len[node] = 1;
	for (auto child : adj[node])
		len[node] += dfs(child);
	return len[node];
}
void solve()
{
	cin >> N >> Q;
	adj = vector<vi>(N + 5);
	save = vi(N + 5);
	len = vi(N + 5, 0);
	for (int i = 2; i <= N; i++)
	{
		cin >> X;
		if (X != i) adj[X].push_back(i);
	}
	for (int i = 1; i <= N; i++)
		sort(all(adj[i]));
	dfs(1);
	cout << "\n\n";
	while (Q--)
	{
		cin >> u >> k;
		if (len[u] < k)
			cout << "-1\n";
		else
			cout << ve[save[u] + (k - 1)] << "\n";
	}
}
int main()
{
	solve();
}
