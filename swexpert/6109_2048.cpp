#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[20][20];
int n;
int tmp[20];

void move(int direction)  //up down left right
{
	int pm = (direction % 2 == 0) ? 1 : -1; //up, left은 +, down right은 -

	int start, end;

	if (pm == 1)
	{
		start = 0;	end = n - 1;
	}
	else
	{
		start = n - 1;	end = 0;
	}
	int flag;

	//up down은 열별로 이동 left right는 행별로 이동
	if (direction < 2)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			flag = 0;
			int cnt;
			for (cnt = 0; cnt < n; cnt++)
				tmp[cnt] = 0;
			cnt = 0; //cnt를 0으로 세팅

			for (int i = start; i != end; )
			{
				if (map[i][j] == 0)//0이면 건너뜀
				{
					i += pm;
					continue;
				}

				int tmpi = i + pm;

				while (!map[tmpi][j])
				{
					if (tmpi == end)
					{
						flag = 1;
						tmp[cnt++] = map[i][j];
						break;
					}
					tmpi += pm;
				}
				if (flag) break;

				if (map[i][j] != map[tmpi][j]) //다르면
				{
					tmp[cnt++] = map[i][j];
					i += pm;
					continue;
				}
				else if (map[i][j] == map[tmpi][j]) //같으면 합치기
				{
					tmp[cnt++] = map[i][j] * 2;
					map[tmpi][j] = 0;
				}
				i += pm;
			}
			if (map[end][j])
				tmp[cnt++] = map[end][j];

			for (int k = cnt; k < n; k++)
				tmp[k] = 0;

			for (int k = 0; k < n; k++)
				map[start + (k*pm)][j] = tmp[k];
		}
	}

	else
	{
		for (int i = 0; i <= n - 1; i++)
		{
			flag = 0;
			int cnt;
			for (cnt = 0; cnt < n; cnt++)
				tmp[cnt] = 0;
			cnt = 0; //cnt를 0으로 세팅

			for (int j = start; j != end;)
			{
				if (map[i][j] == 0)//0이면 건너뜀
				{
					j += pm;
					continue;
				}
				int tmpj = j + pm;

				while (!map[i][tmpj])
				{
					if (tmpj == end)
					{
						flag = 1;
						tmp[cnt++] = map[i][j];
						break;
					}
					tmpj += pm;
				}
				if (flag) break;

				if (map[i][j] != map[i][tmpj]) //다르면
				{
					tmp[cnt++] = map[i][j];
					j += pm;
					continue;
				}
				else if (map[i][j] == map[i][tmpj]) //같으면 합치기
				{
					tmp[cnt++] = map[i][j] * 2;
					map[i][tmpj] = 0;
				}
				j += pm;
			}
			if (map[i][end])
				tmp[cnt++] = map[i][end];

			for (int k = cnt; k < n; k++)
				tmp[k] = 0;

			for (int k = 0; k < n; k++)
				map[i][start + (k*pm)] = tmp[k];
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);


	for (int tc = 1; tc <= t; tc++)
	{
		
		scanf("%d", &n);	
		char dir[10];
		memset(dir, 0, sizeof(dir));
		scanf("%s", &dir);
		int d = 0;
		
		
		if (dir[0] == 'u')
			d = 0;
		else if (dir[0] == 'd')
			d = 1;
		else if (dir[0] == 'l')
			d = 2;
		else if (dir[0] == 'r')
			d = 3;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);


		move(d);
	
		printf("#%d\n", tc);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
	}
	return 0;
}

