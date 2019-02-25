#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int ret;
int N;

void cnt(vector<int> &w, int num, int curword)
{
	if (num == N)
	{
		if (curword == 0)
		{
			ret++;
		}
		return;
	}

	//�� �ܾ� ����
	cnt(w, num + 1, curword&(~w[num]));

	//�� �ܾ� ���� x
	cnt(w, num + 1, curword);

	return;
}

int main()
{
	cin >> N;
	ret = 0;
	vector<int> word(N, 0);

	char tmp[100];
	//a-z 97-122, 26���� �ܾ�

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &tmp);
		for (int j = 0; j < strlen(tmp); j++)
		{
			word[i] |= (1 << ((int)tmp[j] - 97));
		}
	}
	
	int font = (1 << 26) - 1; //26���� 1�� ä���� ����
	//67108863
	
	cnt(word, 0, font);

	cout << ret << endl;
}