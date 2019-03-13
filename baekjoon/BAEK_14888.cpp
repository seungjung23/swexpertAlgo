#include <iostream>
#include <vector>
using namespace std;

vector<long long> num;
int oper[4];
long long max0, min0;
int n;

void cal(int cur, long long ret)
{
	if (cur == n)
	{
		//cout << ret << endl;
		max0 = (max0 < ret) ? ret : max0;
		min0 = (min0 > ret) ? ret : min0;
		return;
	}
	
	if (oper[0] > 0)
	{
		oper[0]--;
		cal(cur + 1, ret + num[cur]);
		oper[0]++;
	}
	if (oper[1] > 0)
	{
		oper[1]--;
		cal(cur + 1, ret - num[cur]);
		oper[1]++;
	}
	if (oper[2] > 0)
	{
		oper[2]--;
		cal(cur + 1, ret * num[cur]);
		oper[2]++;
	}
	if (oper[3] > 0)
	{
		oper[3]--;
		if (ret < 0)
			cal(cur + 1, ((-1 * ret) / num[cur])*(-1));
		else
			cal(cur + 1, ret / num[cur]);
		oper[3]++;
	}
}


int main()
{
	cin >> n;
	num = vector<long long>(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	max0 = -9999987654321;
	min0 = 999987654321;

	cal(1, num[0]);

	cout << max0 <<' '<< min0 << endl;
	
}

