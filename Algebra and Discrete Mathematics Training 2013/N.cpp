#include <iostream>

using namespace std;

bool is_prime (int n)
{
	for (int i = 2; i * 1ll * i <= n; ++i)
		if (n%i == 0)
			return false;
	return true;
}

int main ()
{
	int k;
	cin >> k;
	if (k == 1)
	{
		cout << 2;
		return 0;
	}
	int count = 1;
	for (int i = 3; ; i += 2)
		if (is_prime(i))
		{
			++count;
			if (count == k)
			{
				cout << i;
				return 0;
			}
		}
}