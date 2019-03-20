#include <iostream>
#include <cstring>
using namespace std;
int cache[46];

int fibo(int n)
{
	int &ret = cache[n];
	if (ret != -1)
		return cache[n];
	if (n == 0 || n == 1)
		return cache[n] = n;
	else return cache[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	int ans = fibo(n);
	cout << ans << endl;
}