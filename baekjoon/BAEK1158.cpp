#include <iostream>
#include <list>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	list <int> l;
	for (int i = 1; i <= N; i++)
	{
		l.push_back(i);
	}

	list<int>::iterator cur = l.begin();
	
	cout << '<';

	while (N)
	{
		for (int i = 1; i < M; i++) //M��°�� �ű�
		{
			cur++;
			if (cur == l.end())
				cur = l.begin();
		}
		cout << *(cur);

		if (N != 1)
			cout << ", ";

		cur = l.erase(cur);
		//cur��ġ�� ���Ҹ� �����, �� ������ġ�� ��ȯ

		if (cur == l.end())	cur = l.begin();
		//���� ���� ��ġ�� list�� ���� ��, ó�� ��ġ�� �ְ� �������� ����

		N--;

	}

	cout << '>' << endl;
}