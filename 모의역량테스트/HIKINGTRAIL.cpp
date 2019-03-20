#include <iostream>
#include <vector>
using namespace std;

int ans, n, k;
vector<vector<int>> map;
vector<vector<int>> visit;
int dir[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
				//  상     하      좌     우

void solve(bool cut, int curlen, int x, int y)
{
	int nx, ny;
	int tmp;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dir[i][0];
		ny = y + dir[i][1];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[ny][nx])
			continue;
	
		if (map[ny][nx] >= map[y][x])
		{
			if (cut == false)
				continue;
			if (cut == true && (map[ny][nx] - map[y][x] < k))
			{ //깎을 수 있고, 깎을 수 있는 범위이면
				tmp = map[ny][nx];
				map[ny][nx] = map[y][x] - 1;
				visit[ny][nx] = 1;
				solve(false, curlen + 1, nx, ny);
				visit[ny][nx] = 0;
				map[ny][nx] = tmp;
			}
		}
		else
		{
			visit[ny][nx] = 1;
			solve(cut, curlen + 1, nx, ny);
			visit[ny][nx] = 0;
		}
	}
	ans = (ans < curlen) ? curlen : ans;
}


int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> k;
		map = vector<vector<int>>(n, vector<int>(n, 0));
		visit = vector<vector<int>>(n, vector<int>(n, 0));

		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				max = (max < map[i][j]) ? map[i][j] : max;
			}
		}
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == max)
				{
					visit[i][j] = 1;
					solve(true, 1, j, i);
					visit[i][j] = 0;
				}
			}
		}

		map.clear();
		cout << "#" << tc << ' ' << ans << endl;
	}	
}


