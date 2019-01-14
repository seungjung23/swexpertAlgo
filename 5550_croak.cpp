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

		if (input[0] != 'c') //ó�� ������ c�� �ƴ� ��� -1��ȯ
		{
			printf("#%d -1\n", tc); continue;
		}
		else
		{
			num[0] = 1; //���۽� ó�� �迭�� c�־���
			ans++; //1���� ������ ����

			for (int i = 1; i < len; i++) //���� �ܾ���� �� �ܾ���� �˻�
			{
				int j = 0;
				int tmp = 0;
				switch (input[i])
				{
				case 'c':  //c�̸� k������ ã�ų� ���ο� ������ ����
					tmp = 1;
					for (j = 0; j <= ans; j++)
					{
						if (num[j] == 5)//k�̸� c�� �ٲٰ� ���� �ܾ�� 
						{
							num[j] = 1; break;
						}
						else if (num[j] == 0) //���ο� ������ ���� 
						{
							ans++; num[j]++; break;
						}
					}
					break;

				case 'r':
					tmp = 2;
					for (j = 0; j <= ans; j++)
					{
						if (num[j] == 1)//c�̸� r�� �ٲٰ� ���� �ܾ�� 
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
						if (num[j] == 2)//r�̸� o�� �ٲٰ� ���� �ܾ�� 
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
						if (num[j] == 3)//o�̸� a�� �ٲٰ� ���� �ܾ�� 
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
						if (num[j] == 4)//a�̸� k�� �ٲٰ� ���� �ܾ�� 
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

