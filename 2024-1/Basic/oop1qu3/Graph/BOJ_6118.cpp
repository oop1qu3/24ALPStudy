#include <bits/stdc++.h>
#define fastio std::cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int SIZE = 20001;
vector<int> adj[SIZE];
bool visited[SIZE];
int dist[SIZE];

queue<int> que;

int maxDist = 0;
vector<int> maxDistNode;

void bfs(int start);

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

	int start = 1;
	bfs(1);

	int min_num = *min_element(maxDistNode.begin(), maxDistNode.end());
	cout << min_num << " " << maxDist << " " << maxDistNode.size();
}

void bfs(int start)
{
	que.push(start);
	visited[start] = true;

	while (!que.empty())
	{
		int cur = que.front(); que.pop();

		for (int n : adj[cur])
		{
			if (visited[n] == false)
			{
				que.push(n);
				visited[n] = true;
				dist[n] = dist[cur] + 1;

				if (dist[n] > maxDist)
				{
					maxDist = dist[n];
					maxDistNode.clear();
				}
				maxDistNode.push_back(n);
			}
		}
	}
}
