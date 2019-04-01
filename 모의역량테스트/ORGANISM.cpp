#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 100
using namespace std;

int n, m, k;
int dir[5][2] = { {0,0}, {0,-1},{0,1},{-1,0},{1,0} };

typedef struct
{
	int cnt = 0;
	int dir = 0;
	int maxcnt = 0;
}group;


queue<pair<int, int>> q;
group map[MAXN][MAXN];
group newmap[MAXN][MAXN];
int allcnt;

void newcopy()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = newmap[i][j];
		}
	}
}

int afterone()
{
	int allcnt = 0;
	int num;
	for (int mn = 0; mn < m; mn++)
	{
		memset(newmap, 0, sizeof(newmap));
		allcnt = 0;
		num = q.size();
		int x, y, tmpdir, tmpcnt;
		
		for (int i = 0; i < num; i++)
		{
			x = q.front().first;
			y = q.front().second;
			tmpdir = map[y][x].dir;
			tmpcnt = map[y][x].cnt;

			//다음칸 좌표
			x += dir[tmpdir][0];
			y += dir[tmpdir][1];

			if (x == 0 || y == 0 || x == n - 1 || y == n - 1)
			{
				newmap[y][x].maxcnt = newmap[y][x].cnt = tmpcnt / 2;
				allcnt += newmap[y][x].cnt;

				if (newmap[y][x].cnt)
				{
					q.push(make_pair(x, y));
				}

				if (tmpdir % 2)
				{
					newmap[y][x].dir = tmpdir + 1;
				}
				else
					newmap[y][x].dir = tmpdir - 1;
			}
			else
			{
				if (!newmap[y][x].cnt)//다른 미생물 군집이 왔던 적이 없으면
				{
					q.push(make_pair(x, y));
				}
				allcnt += tmpcnt;
				newmap[y][x].cnt += tmpcnt;
				
				if (newmap[y][x].maxcnt < tmpcnt)
				{
					newmap[y][x].maxcnt = tmpcnt;
					newmap[y][x].dir = tmpdir;
				}
			}
			q.pop();
		}
		newcopy();
	}
	while (!q.empty())
	{
		q.pop();
	}
	return allcnt;
}

void input()
{
	int tmpx, tmpy;
	for (int i = 0; i < k; i++)
	{
		cin >> tmpy >> tmpx;
		q.push(make_pair(tmpx, tmpy));
		cin >> map[tmpy][tmpx].cnt;
		map[tmpy][tmpx].maxcnt = map[tmpy][tmpx].cnt;
		cin >> map[tmpy][tmpx].dir;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		memset(map, 0, sizeof(map));

		cin >> n >> m >> k;
		
		allcnt = 0;
		input();
	
		cout << '#' << tc << ' ' << afterone() << endl;
	}

}