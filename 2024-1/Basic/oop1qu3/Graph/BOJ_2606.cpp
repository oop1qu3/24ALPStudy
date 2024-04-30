#include <bits/stdc++.h>
#define fastio std::cin.tie(0)->sync_with_stdio(0);
using namespace std;

const int SIZE = 101;
vector<int> adj[SIZE];
bool vis[SIZE];

int main()
{
	fastio;

	int N, M; cin >> N >> M;
	while (M--)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> que;
	que.push(1);
	while (!que.empty())
	{
		int cur = que.front(); que.pop();
		for (int nxt : adj[cur])
		{
			if (vis[nxt]) continue;
			que.push(nxt);
			vis[nxt] = 1;
		}
	}

	int count = 0;
	for (int i = 2; i <= N; i++)
	{
		if (vis[i]) count++;
	}

	cout << count;
	return 0;
}
