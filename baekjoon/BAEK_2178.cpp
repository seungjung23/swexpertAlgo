#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> visit;
int n, m;

int dir[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
				//  ╩С     го      аб      ©Л

void solve()
{
	int x, y, nx, ny;
	int cnt = 1;
	bool flag = false;
	visit[0][0] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty() && !flag)
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dir[i][0];
			ny = y + dir[i][1];

			if (nx == m - 1 && ny == n - 1)
			{
				visit[ny][nx] = visit[y][x] + 1;
				flag = true;
				break;
			}


			if (nx < 0 || ny < 0 || nx >= m || ny >= n || map[ny][nx] == 0 || visit[ny][nx])
				continue;
			else
			{
				q.push(make_pair(nx, ny));
				visit[ny][nx] = visit[y][x] + 1;
			}
		}
	}
	
}

void input(int n, int m)
{
	map = vector<vector<int>>(n, vector<int>(m, 0));
	visit = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
}

int main()
{
	cin >> n >> m;
	input(n, m);
	solve();
	cout << visit[n-1][m-1] << endl;
	map.clear();
	visit.clear();
}


