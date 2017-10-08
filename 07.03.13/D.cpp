#include <iostream>
using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i%2 == 1)
		{
			if (m % 2 == 1)
				ans += m/2 + 1;
			else
				ans += m/2;
		}
		else
			ans += m/2;
	}
	cout << ans;
}