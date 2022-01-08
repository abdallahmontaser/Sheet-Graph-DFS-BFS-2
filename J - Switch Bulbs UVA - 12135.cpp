#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
int N, M, K, X, Q, cnt = 1;
string S;
vector<vi>switches;
map<string, int>vis;
void gen()
{
	string T(N, '0'), cur;
	queue<string>qe;
	qe.push(T);
	vis[T] = 0;
	while (!qe.empty())
	{
		cur = qe.front();
		qe.pop();
		for (int i = 0; i < M; i++)
		{
			S = cur;
			for (auto switche : switches[i])
			{
				if (S[switche] == '0')S[switche] = '1';
				else S[switche] = '0';
			}
			if (vis.find(S) == vis.end())
				vis[S] = vis[cur] + 1, qe.push(S);
		}
	}
}
void solve()
{
	cin >> N >> M;
	switches = vector<vi>(M);
	vis.clear();
	for (int i = 0; i < M; i++)
	{
		cin >> K;
		while (K--)
			cin >> X, switches[i].push_back(X);
	}
	cin >> Q;
	gen();
	cout << "Case " << cnt++ << ":\n";
	while (Q--)
	{
		cin >> S;
		reverse(all(S));
		if (vis.find(S) == vis.end())
			cout << "-1\n";
		else
			cout << vis[S] << "\n";
	}
	cout << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
