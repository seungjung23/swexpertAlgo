#include <iostream>

using namespace std;

int main()
{
		int n;
		cin >> n;
		int newn = n;
		int num10, num1, tmpsum;
		int cnt = 0;
		do
		{
			num10 = newn / 10;
			num1 = newn % 10;
			tmpsum = num10 + num1;
			newn = (num1 * 10) + (tmpsum % 10);
			cnt++;
		} while (newn != n);

		cout << cnt << endl;
}