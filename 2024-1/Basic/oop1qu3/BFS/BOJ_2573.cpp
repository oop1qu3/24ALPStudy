#include <bits/stdc++.h>
#define fastio std::cin.tie(0)->sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;

const int SIZE = 300;
int board[SIZE][SIZE] = { 0 };
bool vis[SIZE][SIZE] = { 0 };
int nZeros[SIZE][SIZE] = { 0 };
int nExtraZeros[SIZE][SIZE] = { 0 };

int N, M;
vector<pii> nonZeros;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

inline bool isValid(int, int);
inline bool isZero(pii&);
int bfs(pii);
void melt();

int main()
{
	fastio;
	 
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		int u; cin >> u;
		board[i][j] = u;
		if (u != 0)
			nonZeros.push_back({i, j});
	}

	for (pii& p : nonZeros)
	{
		int cy = p.first;
		int cx = p.second;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isValid(ny, nx) && board[ny][nx] == 0)
				nZeros[cy][cx]++;
		}
	}

	int cnt = 0;
	while (true)
	{
		melt(); cnt++;

		if (nonZeros.size() == 0) 
			{ cout << 0; break; }
		
		if (bfs(nonZeros[0]) != nonZeros.size())
			{ cout << cnt; break; }
	}

	return 0;
}

inline bool isValid(int y, int x)
{
	return (0 <= y && y < N) && (0 <= x && x < M);
}

bool isZero(pii& p)
{
	int cy = p.first;
	int cx = p.second;

	if ((board[cy][cx] -= nZeros[cy][cx]) <= 0)
	{
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isValid(ny, nx) && board[ny][nx] > 0)
				nExtraZeros[ny][nx]++;
		}
		return true;
	}
	return false;
}

void melt()
{
	for (int i = 0; i < N; i++)
		fill(nExtraZeros[i], nExtraZeros[i] + M, false);

	auto& v = nonZeros;
	v.erase(remove_if(v.begin(), v.end(), isZero), v.end());

	for (pii& p : nonZeros)
	{
		int cy = p.first;
		int cx = p.second;

		nZeros[cy][cx] += nExtraZeros[cy][cx];
	}
}

int bfs(pii start)
{
	queue<pii> que;
	int cnt = 0;

	que.push(start);
	vis[start.first][start.second] = true;
	cnt++;

	while (!que.empty())
	{
		pii cur = que.front(); que.pop();

		int cy = cur.first;
		int cx = cur.second;

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (isValid(ny, nx) && board[ny][nx] > 0 && vis[ny][nx] == false)
			{
				que.push({ ny, nx });
				vis[ny][nx] = true;
				cnt++;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
		fill(vis[i], vis[i] + M, false);

	return cnt;
}
