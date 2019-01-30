#include <iostream>
#include <list>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++)
	{
		int N, K;
		cin >> N >> K;

		list <int> l;
		for (int i = 1; i <= N; i++)
		{
			l.push_back(i);
		}

		list<int>::iterator cur = l.begin();

		while (N > 2)
		{
			cur = l.erase(cur);
			//cur위치의 원소를 지우고, 그 다음위치를 반환

			if (cur == l.end())	cur = l.begin();
			//지운 다음 위치가 list의 끝일 때, 처음 위치를 넣고 원형으로 연결

			N--;

			for (int i = 1; i < K; i++) //K-1번 위치 옮김
			{
				cur++;
				if (cur == l.end())
					cur = l.begin();
			}
		}

		cout << l.front() << ' ' << l.back() << endl;
	}
}