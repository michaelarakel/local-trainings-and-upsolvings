#include <iostream>

using namespace std;

int main ()
{
	long long n;
	cin >> n;
	for (int i = 2; 1ll * i * i <= n; i++)
	{
		while (n%i == 0)
		{
			n /= i;
			cout << i;
			if (n != 1)
				cout << '*';
		}
	}
	if (n > 1)
		cout << n;
}