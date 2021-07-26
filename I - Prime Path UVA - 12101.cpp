#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi>adj(1e4 + 2);
bool is_prime(int X)
{
	for (int i = 2; i * i <= X; i++)
		if (X % i == 0)
			return false;
	return true;
}
bool ok(int X, int Y)
{
	int cnt = 0;
	while (X)
		cnt += (X % 10 != Y % 10), X /= 10, Y /= 10;
	return (cnt == 1);
}
void Build_Graph()
{
	vi prime;
	for (int i = 1000; i <= 9999; i++)
		if (is_prime(i))
			prime.push_back(i);
	for (int i = 0; i < prime.size(); i++)
		for (int j = i + 1; j < prime.size(); j++)
			if (i != j && ok(prime[i], prime[j]))
				adj[prime[i]].push_back(prime[j]), adj[prime[j]].push_back(prime[i]);
}
void BFS()
{
	int u, v, cur; cin >> u >> v;
	queue<int>qe;
	vi len(1e4 + 1, 1e7);
	qe.push(u), len[u] = 0;
	while (!qe.empty())
	{
		cur = qe.front(), qe.pop();
		if (cur == v)
			break;
		for (auto child : adj[cur])
			if (len[child] == 1e7)
				qe.push(child), len[child] = len[cur] + 1;
	}
	if (len[v] == 1e6)
		cout << "Impossible\n";
	else
		cout << len[v] << "\n";
}
int main()
{
	Build_Graph();
	int T ; cin >> T;
	while (T--)
		BFS();
}
