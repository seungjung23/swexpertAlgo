#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int  m, n;
bool person[2][101][9];
queue<pair<int, int>> map[11][11]; //사람, 시간

vector<int> p;
int dir[5][2] = { {0,0}, {0,-1}, {1,0}, {0,1}, {-1,0} };
						// 상     우     하      좌 

int cal()
{
	int sum = 0, max = 0, tmpsum = 0;

	for (int i = 0; i <= m; i++)
	{
		max = 0;

		if (!person[0][i][0] && !person[1][i][0]) //둘다 충전범위 밖
		{
			continue;
		}

		if (!person[0][i][0]) //b만 충전영역존재
		{
			for (int j = 1; j <= n; j++)
			{
				if (person[1][i][j])
				{
					max = (max < p[j]) ? p[j] : max;
				}
			}
			sum += max;
			continue;
		}
		if (!person[1][i][0]) //a만 충전영역존재
		{
			for (int j = 1; j <= n; j++)
			{
				if (person[0][i][j])
				{
					max = (max < p[j]) ? p[j] : max;
				}
			}
			sum += max;
			continue;
		}

		for (int ai = 1; ai <= n; ai++)
		{
			for (int bi = 1; bi <= n; bi++)
			{
				if (person[0][i][ai] && person[1][i][bi])
				{
					if (ai == bi)
					{
						max = (max < p[ai]) ? p[ai] : max;
					}
					else
					{
						max = (max < (p[ai] + p[bi])) ? (p[ai] + p[bi]) : max;
					}
				}
			}
		}
		sum += max;
		continue;
	}

	return sum;
}

void input()
{
	int x, y, tmpdir;

	x = y = 1;
	map[y][x].push(make_pair(0, 0));
	for (int i = 1; i <= m; i++)
	{
		cin >> tmpdir;
		x += dir[tmpdir][0];
		y += dir[tmpdir][1];
		map[y][x].push(make_pair(0, i));
	}

	x = y = 10;
	map[y][x].push(make_pair(1, 0));
	for (int i = 1; i <= m; i++)
	{
		cin >> tmpdir;
		x += dir[tmpdir][0];
		y += dir[tmpdir][1];
		map[y][x].push(make_pair(1, i));
	}
}

void in()
{
	int tmpx, tmpy, tmpc;
	for (int pi = 1; pi <= n; pi++)
	{
		cin >> tmpx >> tmpy >> tmpc >> p[pi];

		for (int i = tmpy - tmpc; i <= tmpy + tmpc; i++)
		{
			for (int j = tmpx - tmpc; j <= tmpx + tmpc; j++)
			{
				if (i < 1 || j < 1 || i > 10 || j > 10)
					continue;
				if (abs(j - tmpx) + abs(i - tmpy) <= tmpc)
				{
					for (int qu = 0; qu < map[i][j].size(); qu++)
					{
						person[map[i][j].front().first][map[i][j].front().second][0] = true;
						person[map[i][j].front().first][map[i][j].front().second][pi] = true;
						map[i][j].push(make_pair(map[i][j].front().first, map[i][j].front().second));
						map[i][j].pop();
					}
				}
			}
		}
	}
}



int main()
{
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		cin >> m >> n;
		p = vector<int>(n + 1, 0);
		memset(person, false, sizeof(person));
		input();
		in();
		cout << "#" << tc << ' ' << cal() << endl;
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				while (!map[i][j].empty())
				{
					map[i][j].pop();
				}
			}
		}
		p.clear();
	}
}
