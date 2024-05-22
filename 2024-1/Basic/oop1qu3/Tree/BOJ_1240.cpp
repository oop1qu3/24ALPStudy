#include <bits/stdc++.h>
#define fastio std::cin.tie(0)->sync_with_stdio(0)
using namespace std;

typedef struct 
{
	int node;
	int dist;
} edge;

vector<edge> adj[1001];
int parent[1001];
int depth[1001];
int dist[1001];

void dfs(int cur);
int findLCA(int u, int v);

int main()
{
    fastio;
    
	int n, m; 
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) 
	{
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ v, d });
		adj[v].push_back({ u, d });
	}

	dfs(1);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		int lca = findLCA(u, v);
		cout << dist[u] + dist[v] - 2 * dist[lca] << "\n";
	}
}

void dfs(int cur) 
{
	for (edge nxt : adj[cur])
	{
		if (parent[cur] == nxt.node) continue;

		parent[nxt.node] = cur;
		dist[nxt.node] = dist[cur] + nxt.dist;
		depth[nxt.node] = depth[cur] + 1;

		dfs(nxt.node);
	}
}

int findLCA(int u, int v)
{
	if (depth[u] < depth[v]) swap(u, v);

	while (depth[u] != depth[v])
		u = parent[u];

	while (true)
	{
		if (u == v) return u;

		u = parent[u];
		v = parent[v];
	}
}
