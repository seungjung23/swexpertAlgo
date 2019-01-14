#include <stdio.h>
#include <string.h>

int num[1000];
char input[2501];

int main()
{
	int t;
	scanf("%d", &t);
	int ans;

	for (int tc = 1; tc <= t; tc++)
	{
		for (int i = 0; i < 500; i++)
			num[i] = 0;
		ans = 0;
		scanf("%s", &input);
		int len = strlen(input);

		if (input[0] != 'c') //처음 시작이 c가 아닐 경우 -1반환
		{
			printf("#%d -1\n", tc); continue;
		}
		else
		{
			num[0] = 1; //시작시 처음 배열에 c넣어줌
			ans++; //1개의 개구리 생성

			for (int i = 1; i < len; i++) //다음 단어부터 끝 단어까지 검색
			{
				int j = 0;
				int tmp = 0;
				switch (input[i])
				{
				case 'c':  //c이면 k다음을 찾거나 새로운 개구리 생성
					tmp = 1;
					for (j = 0; j <= ans; j++)
					{
						if (num[j] == 5)//k이면 c로 바꾸고 다음 단어로 
						{
							num[j] = 1; break;
						}
						else if (num[j] == 0) //새로운 개구리 생성 
						{
							ans++; num[j]++; break;
						}
					}
					break;

				case 'r':
					tmp = 2;
					for (j = 0; j <= ans; j++)
					{
						if (num[j] == 1)//c이면 r로 바꾸고 다음 단어로 
						{
							num[j] = 2; break;
						}
					}
					if (j == ans + 1)
					{
						ans = -1; break;
					}
					break;
				case 'o':
					tmp = 3;
					for (j = 0; j <= ans; j++)
					{
						if (num[j] == 2)//r이면 o로 바꾸고 다음 단어로 
						{
							num[j] = 3; break;
						}
					}
					if (j == ans + 1)  
					{
						ans = -1; break;
					}
					break;
				case 'a':
					tmp = 4;
					for (j = 0; j <= ans; j++)
					{
						if (num[j] == 3)//o이면 a로 바꾸고 다음 단어로 
						{
							num[j] = 4; break;
						}
					}
					if (j == ans + 1)  
					{
						ans = -1; break;
					}
					break;
				case 'k':
					tmp = 5;
					for (j = 0; j <= ans; j++)
					{
						if (num[j] == 4)//a이면 k로 바꾸고 다음 단어로 
						{
							num[j] = 5; break;
						}
					}
					if (j == ans + 1)  
					{
						ans = -1; break;
					}
					break;

				}

			}
		}
		if (ans == -1)
			printf("#%d %d\n", tc, ans);
		else
		{
			int flag = 0;
			for (int i = 0; i < ans; i++)
			{
				if (num[i] > 0 && num[i] < 5)
				{
					printf("#%d -1\n", tc); flag = 1; break;
				}
			}
			if (!flag)
				printf("#%d %d\n", tc, ans);
		}
	}

}

