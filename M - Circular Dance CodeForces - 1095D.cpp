#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void solve()
{
	int N, d = 1; cin >> N;
	vector<pair<int, int>>ve(N + 3);
	vi ans, par(N + 2, -1);
	for (int i = 1; i <= N; i++)
		cin >> ve[i].first >> ve[i].second;
	if (N == 3)
	{
		cout << "1 2 3";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if ((ve[ve[i].first].first == ve[i].second) || (ve[ve[i].first].second == ve[i].second))
			par[i] = ve[i].first;
		else
			par[i] = ve[i].second;
	}
	ans.push_back(1);
	while (par[d] != 1)
		ans.push_back(par[d]), d = par[d];
	for (auto& it : ans)
		cout<<it<<" ";
}
int main()
{
	solve();
}
