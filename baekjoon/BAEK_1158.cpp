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
		for (int i = 1; i < M; i++) //M번째로 옮김
		{
			cur++;
			if (cur == l.end())
				cur = l.begin();
		}
		cout << *(cur);

		if (N != 1)
			cout << ", ";

		cur = l.erase(cur);
		//cur위치의 원소를 지우고, 그 다음위치를 반환

		if (cur == l.end())	cur = l.begin();
		//지운 다음 위치가 list의 끝일 때, 처음 위치를 넣고 원형으로 연결

		N--;

	}

	cout << '>' << endl;
}