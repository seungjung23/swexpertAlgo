#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *price;
int n;

int findmax(int num)
{
	int tmpmax = 0;
	int maxn = num;

	for (int i = num; i < n; i++)
	{
		if (tmpmax < price[i])
		{
			tmpmax = price[i];
			maxn = i;
		}
	}
	if (maxn == num)
		return -1;

	return maxn;
}

int main()
{
	int t;
	scanf("%d", &t);
	
	long long ans;

	for (int tc = 1; tc <= t; tc++)
	{
		ans = 0;
		scanf("%d", &n);
		price = (int *)malloc(sizeof(int)*n);
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &price[i]);
		}
		
		int j = 0;
		while (j<n)
		{
			int mxn = findmax(j);
			
			if (mxn == -1)
			{
				j++;
				continue;
			}
			int out = 0;


			for (int i = j; i < mxn; i++)
			{
				out += price[i];
			}
			
			ans += (mxn - j)*price[mxn] - out;
		
			j = mxn + 1;
		}
		
		printf("#%d %lld\n", tc, ans);
	}
	return 0;
}

