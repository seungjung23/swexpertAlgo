#include <stdio.h>
#include <string.h>


int map[102][102];
int n;
int max;
int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
				// 0상	  1하	 2좌   3우

int block[6][4] = {
	{ 0,0,0,0 },
	{ 1,3,0,2 }, //1 상->하, 하->우, 좌->상, 우->좌
	{ 3,0,1,2 }, //2 상->우, 하->상, 좌->하, 우->좌
	{ 2,0,3,1 }, //3 상->좌, 하->상, 좌->우, 우->하
	{ 1,2,3,0 }, //4 상->하, 하->좌, 좌->우, 우->상
	{ 1,0,3,2 }  //5 상->하, 하->상, 좌->우, 우->좌
};


void findhole(int *x, int *y, int num)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j] == num && (*x != j) && (*y != i))
			{
				*x = j, *y = i; return;
			}
}

void score(int x, int y, int d)
{
	int sc = 0;
	int nx = x, ny = y;

	while (1)
	{
		nx += dir[d][0];
		ny += dir[d][1];
		
		if ((nx == x && ny == y) || map[ny][nx] == -1)
		{
			max = (max < sc) ? sc : max;
			break;
		}
	
		if (map[ny][nx] == 0) //장애물 없으면 다음 칸으로
			continue;

		else if (map[ny][nx] >= 1 && map[ny][nx] <= 5)
		{
			d = block[map[ny][nx]][d];
			sc++;			
		}

		else if (map[ny][nx] >= 6 && map[ny][nx] <= 10)
		{
			findhole(&nx, &ny, map[ny][nx]);
		}
	}
	return;
}

void setting()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);

	//양쪽 위 아래에 벽만들기
	for (int i = 0; i <= n + 1; i++)
	{
		map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = 5;
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		scanf("%d", &n);
		max = 0;

		memset(map, 0, sizeof(map));

		setting();

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{	
				if (map[i][j] == 0)
					for (int k = 0; k < 4; k++)
						score(i, j, k);
			}

		printf("#%d %d\n", tc, max);
	}
	return 0;
}

