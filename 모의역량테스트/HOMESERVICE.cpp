#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int n, m;
int maxcnt;
int kcache[22];

bool isrange(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n)
		return false;
	else return true;
}

void solve(int x, int y, int k)
{
	int cnt = 0;

	//위쪽 아래쪽 확인
	int xs, xe;
	for (int i = 1; i < k; i++)
	{
		xs = x - i + 1;
		xe = x + i - 1;
		for (int xi = xs; xi <= xe; xi++)
		{
			if (isrange(xi, y - k + i) && arr[y - k + i][xi])
				cnt++;
			if (isrange(xi, y + k - i) && arr[y + k - i][xi])
				cnt++;
		}
	}
	//가운데 확인
	xs = x - k + 1;
	xe = x + k - 1;
	for (int xi = xs; xi <= xe; xi++)
	{
		if (isrange(xi, y) && arr[y][xi])
			cnt++;
	}


	if (cnt*m - kcache[k] < 0)
	{
		return;
	}

	maxcnt = (maxcnt < cnt) ? cnt : maxcnt;
}



int main()
{
	int t;
	cin >> t;

	//k저장해놓기
	kcache[0] = 0;
	for (int i = 1; i <= 21; i++)
	{
		kcache[i] = (i*i) + ((i - 1)*(i - 1));
	}

	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m;

		arr = vector<vector<int>>(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		maxcnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k <= n; k++)
				{
					solve(i, j, k);
				}
			}
		}


		cout << '#' << tc << ' ' << maxcnt << endl;
	}
}