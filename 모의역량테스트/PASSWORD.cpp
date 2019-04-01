#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;
int  n, k;
vector<int> arr;
vector<long long> pass;

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> k;
		arr = vector<int>(n, 0);
		pass = vector<long long>(n, 0);
		int cnt = n / 4;
		char tmp = ' ';
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			if (tmp >= 'A'&& tmp <= 'F')
			{
				arr[i] = (int)(tmp - 'A') + 10;
			}
			else
			{
				arr[i] = (int)(tmp - '0');
			}
		}
		
		int nn, ncnt;
		int tmpn;
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			nn = i / cnt; //몇번째 집합에 속해있는지
			ncnt = i % cnt; //집합에서 몇번째 숫자인지
			tmpn = arr[i] * pow(16, cnt - 1 - ncnt);
			flag = 0;
			for (int j = 0; j < cnt; j++)
			{
				if (nn + j * 4 + flag == 4 * (j + 1))
				{
					pass[nn + j * 4 + flag - 4] += tmpn;
				}
				else
				{
					pass[nn + j * 4 + flag] += tmpn;
				}
				if (tmpn < 16)
				{
					tmpn *= pow(16, cnt - 1);
					flag = 1;
					continue;
				}
				tmpn /= 16;
			}
		}
	
	
		sort(pass.begin(), pass.end(), greater<int>());
		
	
		for (int i = 0; i < k; i++)
		{
			if (pass[i] == pass[i + 1])
				k++;
		}

		cout << '#' << tc << ' ' << pass[--k] << endl;
		arr.clear();
		pass.clear();
	}
}
