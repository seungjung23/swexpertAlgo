#include <iostream>
#include <vector>
#define max(a,b) (a<b)?b:a

using namespace std;
int ans;
int N;

vector<vector<int>> cache;
vector<vector<int>> map;

int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };

int panda(int x, int y)
{
	int &ret = cache[y][x];
	if (ret != -1)return ret;

	ret = 1; //√÷º“
	int tmp = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;

		if (map[ny][nx] > map[y][x])
		{
			tmp = 1 + panda(nx, ny);
			ret = (ret < tmp) ? tmp : ret;
		}
	}
	return ret;
}



int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		vector<int> ele(N, -1);
		map.push_back(ele);
		cache.push_back(ele);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}

	ans = 0;

	int tmp = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			tmp = panda(j, i);
			ans = (ans < tmp) ? tmp : ans;
		}

	cout << ans << endl;
	map.clear();
	cache.clear();


}