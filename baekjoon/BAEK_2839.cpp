#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int cnt = 0;

	while (1)
	{
		if (n % 5 == 0)
		{
			cnt += n / 5;
			break;
		}
		
		if (n < 3)
		{
			cout << -1 << endl;
			return 0;
		}

		n -= 3;
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}

