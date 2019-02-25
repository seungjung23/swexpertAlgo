#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main ()
{
	int n;
	cin >> n;

	string tmp;

	int stack[10000] = { 0, };
	int cnt = 0;
	int tmpint;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == "push")
		{
			cin >> tmpint;
			stack[cnt++] = tmpint;
		}

		else if (tmp == "pop")
		{
			if (cnt > 0)
			{
				cout << stack[--cnt] << endl;
			}
			else
				cout << -1 << endl;
		}
		
		else if (tmp == "size")
		{
			cout << cnt << endl;
		}

		else if (tmp == "empty")
		{
			if (cnt == 0)
				cout << 1 << endl;
			else cout << 0 << endl;
		}

		else if (tmp == "top")
		{
			if (cnt == 0)
				cout << -1 << endl;
			else
				cout << stack[cnt - 1] << endl;
		}
	}
}