#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int map[1001][1001];
int visit[1001];
queue<int> q;
int n, m, start;

void dfs(int num)
{
	visit[num] = 1;
	cout << num << ' ';
	for (int i = 1; i <= n; i++)
	{
		if (map[num][i] == 1 && !visit[i])
		{
			dfs(i);
		}
	}
}

void bfs(int s)
{
	visit[s] = 1;
	q.push(s);
	int cur = s;
	
	while (!q.empty())
	{
		cur = q.front();
		cout << cur << ' ';

		for (int i = 1; i <= n; i++)
		{
			if (map[cur][i] && !visit[i])
			{
				visit[i] = 1;
				q.push(i);
			}
		}
		q.pop();
	}
}


int main()
{
	cin >> n >> m >> start;
	memset(map, 0, sizeof(map));
	
	int tmp1, tmp2;

	for (int i = 0; i < m; i++)
	{
		cin >> tmp1 >> tmp2;
		map[tmp1][tmp2] = map[tmp2][tmp1] = 1;
	}

	memset(visit, 0, sizeof(visit));
	dfs(start);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	bfs(start);

	return 0;
}

