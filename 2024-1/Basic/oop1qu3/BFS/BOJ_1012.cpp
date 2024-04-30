#include <bits/stdc++.h>
#define fastio std::cin.tie(0)->sync_with_stdio(0);
using namespace std;

typedef pair<int, int> pii;

const int SIZE = 50;
bool board[SIZE][SIZE];
bool vis[SIZE][SIZE];
queue<pii> que;

int M, N, K;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void test();
void bfs(pii);

int main()
{
	fastio;

	int T; cin >> T;
	while (T--)
		test();
}

void test()
{
	cin >> M >> N >> K;

	while (K--)
	{
		int X, Y; cin >> X >> Y;
		board[Y][X] = 1;
	}

	int count = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		if (board[i][j] == 1 && vis[i][j] == false)
		{
			bfs({ i, j });
			count++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		fill(board[i], board[i] + M, 0);
		fill(vis[i], vis[i] + M, false);
	}

	cout << count << "\n";
}

void bfs(pii start)
{
	que.push(start);
	vis[start.first][start.second] = true;

	while (!que.empty())
	{
		pii cur = que.front(); que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if ((0 <= nx && nx < M) && (0 <= ny && ny < N) && 
				(board[ny][nx] == 1) && (vis[ny][nx] == false))
			{
				que.push({ ny, nx });
				vis[ny][nx] = true;
			}
		}
	}
}
