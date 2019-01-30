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
			//cur��ġ�� ���Ҹ� �����, �� ������ġ�� ��ȯ

			if (cur == l.end())	cur = l.begin();
			//���� ���� ��ġ�� list�� ���� ��, ó�� ��ġ�� �ְ� �������� ����

			N--;

			for (int i = 1; i < K; i++) //K-1�� ��ġ �ű�
			{
				cur++;
				if (cur == l.end())
					cur = l.begin();
			}
		}

		cout << l.front() << ' ' << l.back() << endl;
	}
}