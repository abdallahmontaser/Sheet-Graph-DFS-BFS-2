#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int flibBit(int num, int idx)
{
	return  num ^ (1 << idx);
}
void solve()
{
	int N, M, K, u, v, cur, tem, temp, len[10][1024], count, cnt = 1; 
	while (cin >> N >> M >> K)
	{
		if (!N && !M && !K)
			break;
		vector<vi>adj(N), adj2(N);
		vector <vector< pair<int, int>>> par(N, vector< pair<int, int>>(1024, { -1,-1 }));
		clr(len, -1);
		for (int i = 0; i < M; i++)
			cin >> u >> v, u--, v--, adj[u].push_back(v), adj[v].push_back(u);
		for (int i = 0; i < K; i++)
			cin >> u >> v, u--, v--, adj2[u].push_back(v);
		queue<pair<int, int>>qe;
		qe.push({ 0,1 });
		len[0][1] = 0;
		while (!qe.empty())
		{
			cur = qe.front().first;
			tem = qe.front().second;
			qe.pop();
			if (cur == N - 1 && tem == flibBit(0, N - 1))
				break;
			for (int mask = 0; mask < (1 << adj2[cur].size()); mask++)
			{
				temp = tem, count = 0;
				for (int bit = 0; bit < adj2[cur].size(); bit++)
				{
					if ((mask & (1 << bit)) && adj2[cur][bit] != cur)
						temp = flibBit(temp, adj2[cur][bit]), count++;
					if (len[cur][temp] == -1)
					{
						qe.push({ cur,temp });
						len[cur][temp] = len[cur][tem] + count;
						par[cur][temp] = { cur,tem };
					}
				}
			}
			for (auto child : adj[cur])
			{
				if (len[child][tem] == -1 && (tem & (1 << child)))
				{
					par[child][tem] = { cur,tem };
					qe.push({ child,tem }), len[child][tem] = len[cur][tem] + 1;
				}
			}
		}
		if (len[N - 1][flibBit(0, N - 1)] == -1)
			cout << "Villa #" << cnt++ << "\n" << "The problem cannot be solved.\n";
		else
		{
			cout << "Villa #" << cnt++ << "\n";
			cout << "The problem can be solved in " << len[N - 1][flibBit(0, N - 1)] << " steps:\n";
			vector<string>ans;
			pair<int, int>d = par[N - 1][flibBit(0, N - 1)];
			int cur_room = N - 1;
			int cur_light = flibBit(0, N - 1);
			while (d != make_pair(-1, -1))
			{
				if (cur_room == d.first)
				{
					for (int bit = 0; bit < N; bit++)
					{
						if ((cur_light & (1 << bit)) != (d.second & (1 << bit)))
						{
							if ((cur_light & (1 << bit)) == 0)
								ans.push_back("- Switch off light in room " + to_string(bit + 1) + ".");
							else
								ans.push_back("- Switch on light in room " + to_string(bit + 1) + ".");
						}
					}
				}
				else
					ans.push_back("- Move to room " + to_string(cur_room + 1) + ".");
				cur_room = d.first;
				cur_light = d.second;
				d = par[d.first][d.second];
			}
			reverse(all(ans));
			for (auto& it : ans)
				cout << it << "\n";
		}
		cout << "\n";
	}
}
int main()
{
		solve();
}
