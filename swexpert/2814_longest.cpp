#include <stdio.h>
int map[11][11];
int check[11];
int ans;
int n, m;

void way(int num, int length)
{
	int flag = 0; 

	for (int i = 1; i <= n; i++)
	{
		if (map[i][num] == 1 && !check[i])
		{
			check[num] = check[i] = 1;
			way(i, length + 1);
			check[num] = check[i] = 0;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		ans = (length > ans) ? length : ans;
		return;
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		ans = 0;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = 0;
			}
		int tmpa, tmpb;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &tmpa, &tmpb);
			map[tmpa][tmpb] = map[tmpb][tmpa] = 1;
		}
		for (int i = 1; i <= n; i++)
			check[i] = 0;

		for (int i = 1; i <= n; i++)
			way(i, 1);

		printf("#%d %d\n", tc, ans);
	}
	return 0;
}

